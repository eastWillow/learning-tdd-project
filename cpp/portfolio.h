#ifndef _PORTFOLIO_
#define _PORTFOLIO_

#include <string>
#include <vector>
#include <numeric> //std::accumulate

class Portfolio{
    private:
    std::vector<Money> moneys;
    double convert(Money aMoney, std::string aCurrency){
        if(aMoney.currency == aCurrency){
            return aMoney.amount;
        }
        return aMoney.amount * 1.2;
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