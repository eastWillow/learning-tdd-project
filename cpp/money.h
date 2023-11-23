#ifndef _MONEY_
#define _MONEY_

#include <string>
#include <vector>

class Money{
    public:
    double amount;
    std::string currency;
    Money(double amount, std::string currency){
        this->amount = amount;
        this->currency = currency;
    }
    Money times(double multiplier){
        return Money(this->amount * multiplier, this->currency);
    }
    Money divide(double divisor){
        return Money(this->amount / divisor, this->currency);
    }
    // Overload equality operator for Point objects
    bool operator==(const Money& other) const {
        bool equal = (this->amount == other.amount) && (this->currency == other.currency);
        if(!equal){
            std::cout << "Values differ: ";
            if(this->amount != other.amount){
                std::cout << "amount: " << this->amount << " != " << other.amount << "; ";
            }
            if(this->currency != other.currency){
                std::cout << "currency: " << this->currency << " != " << other.currency << "; ";
            }
        }
        return equal;
    }
};

#endif