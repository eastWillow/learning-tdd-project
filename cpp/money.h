#ifndef _MONEY_
#define _MONEY_

#include <string>
#include <vector>
#include <iomanip>

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
        return equal;
    }
    // Overload Display Value in Google Test
    friend std::ostream& operator<<(std::ostream& os, const Money& obj) {
        os  << "Money { amount: " << std::fixed << std::setprecision(2) << obj.amount 
            << ", currency: " << std::fixed << std::setprecision(2) << obj.currency 
            << " }";
        return os;
    }
};

#endif