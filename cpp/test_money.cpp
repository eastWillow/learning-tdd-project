#include "gtest/gtest.h"
#include <string>

class Money{
    public:
    int amount;
    std::string currency;
    Money(int amount, std::string currency){
        this->amount = amount;
        this->currency = currency;
    }
    Money times(int multiplier){
        return Money(this->amount * multiplier, this->currency);
    }
    Money divide(int divisor){
        return Money(this->amount / divisor, this->currency);
    }
    // Overload equality operator for Point objects
    bool operator==(const Money& other) const {
        return (this->amount == other.amount) && (this->currency == other.currency);
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

auto orignalMoney = Money(4002,"KRW");
auto actualMoneyAfterDivision = orignalMoney.divide(4);
auto expectedMoneyAdterDivision = Money(1000.5, "KRW");

TEST(TestMoney, TestDivisions)
{
    EXPECT_EQ(actualMoneyAfterDivision, expectedMoneyAdterDivision);
}
