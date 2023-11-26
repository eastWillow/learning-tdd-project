#ifndef _PORTFOLIO_
#define _PORTFOLIO_

#include <string>
#include <vector>
#include <numeric> //std::accumulate
#include <map>
#include <sstream>

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
        double exchangeRate = 1; 
        try{
            exchangeRate = exchangeRates.at(key);//Please use at because this will throw the exception of type std::out_of_range
        }
        catch(std::out_of_range& ex)
        {
            throw std::out_of_range(key);
        }
        return aMoney.amount * exchangeRate; 
    }
    public:
    void add(Money a){
        std::vector<Money> moneys = {a};
        this->moneys.insert(this->moneys.end(),moneys.begin(),moneys.end());
    }
    Money evaluate(std::string currency){
        double total = 0.0;
        std::vector<std::string> failures;
        std::stringstream failureMessage;
        for(const auto &money : moneys){
            try{
                total += convert(money, currency);
            }catch(std::out_of_range& ex){
                failures.insert(failures.end(), ex.what());
            }
        }
        if(failures.size() == 0){
            return Money(total, currency);
        }
        
        failureMessage << "Missing exchange rate(s):[" ;
        for(const auto &failure : failures){
            failureMessage << failure << ",";
        }
        failureMessage << "]";
        throw std::out_of_range(failureMessage.str());
    }
};

#endif