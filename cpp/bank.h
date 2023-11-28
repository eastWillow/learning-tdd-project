#ifndef _BANK_
#define _BANK_

#include "money.h"
#include <vector>
#include <map>

class Bank{
    private:
        std::map<std::string, double> exchangeRates;

    public:
        void addExchangeRate(std::string currencyFrom, std::string currencyTo, double rate){
            std::pair<std::map<std::string, double>::iterator, bool> result;
            result = exchangeRates.insert(std::make_pair(currencyFrom + "->" + currencyTo, rate));

            //insert_or_assign only in C++17, but this project is use C++11
            //so i need to create this one
            if(result.second == false)
            {
                exchangeRates[currencyFrom + "->" + currencyTo] = rate;
            }
        }

        Money convert(Money aMoney, std::string aCurrency){
            if(aMoney.currency == aCurrency){
                return Money(aMoney.amount, aCurrency);
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
            return Money(aMoney.amount * exchangeRate, aCurrency);
        }
};

#endif