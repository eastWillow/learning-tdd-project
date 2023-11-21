#include "gtest/gtest.h"
#include <string>

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

auto fiver = Money(5,"USD");
auto tenner = fiver.times(2);

TEST(TestMoney, TestMultiplicationInDollars)
{
    EXPECT_EQ(tenner.amount, 10); 
    EXPECT_EQ(tenner.currency, "USD");
}

auto tenEuros = Money(10, "EUR");
auto twentyEuros = tenEuros.times(2);

TEST(TestMoney, TestMultiplicationInEuros)
{
    EXPECT_EQ(twentyEuros.amount, 20);
    EXPECT_EQ(twentyEuros.currency, "EUR");
}

auto orignalMoney = Money(2500.5,"KRW");
auto actualMoneyAfterDivision = orignalMoney.divide(2.5);
auto expectedMoneyAdterDivision = Money(1000.2, "KRW");

TEST(TestMoney, TestDivisions)
{
    EXPECT_EQ(actualMoneyAfterDivision, expectedMoneyAdterDivision);
}
