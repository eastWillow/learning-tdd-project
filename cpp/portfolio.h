#ifndef _PORTFOLIO_
#define _PORTFOLIO_

#include <string>
#include <vector>
#include <numeric> //std::accumulate
#include <map>

class Portfolio{
    private:
    std::vector<Money> moneys;
    std::map<std::string, double> exchangeRates {
        std::make_pair("EUR->USD", 1.2),
        std::make_pair("USD->KRW", 1100)};
    double convert(Money aMoney, std::string aCurrency){
        if(aMoney.currency == aCurrency){
            return aMoney.amount;
        }
        std::string key = aMoney.currency + "->" + aCurrency;
        return aMoney.amount * exchangeRates[key];
    }
    public:
    void add(Money a, Money b){
        std::vector<Money> moneys = {a, b};
        this->moneys.insert(this->moneys.end(),moneys.begin(),moneys.end());
    }
    Money evaluate(std::string currency){
        double total = std::accumulate(moneys.begin(), moneys.end(), 0,
                                        [this,currency](double accumulator, const Money& Money) {
                                            return accumulator + convert(Money, currency);
                                            }); // accumulate from 0 
        return Money(total, currency);
    }
};

#endif