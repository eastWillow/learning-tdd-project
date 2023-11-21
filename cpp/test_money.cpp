#include "gtest/gtest.h"
#include <string>

class Dollar{
    public:
    int amount;
    Dollar(int amount){
        this->amount = amount;
    }
    Dollar times(int multiplier){
        return Dollar(this->amount * multiplier);
    }
};

auto fiver = Dollar(5);
auto tenner = fiver.times(2);

TEST(TestMoney, TestMultiplication)
{
    EXPECT_EQ(tenner.amount, 10); 
}

class Money{
    public:
    int amount;
    std::string currency;
    Money(int amount, std::string currency){
        this->amount = amount;
        this->currency = currency;
    }
    Money times(int multiplier){
        return Money(this->amount * multiplier,"EUR");
    }
};

auto tenEuros = Money(10, "EUR");
auto twentyEuros = tenEuros.times(2);

TEST(TestMoney, TestMultiplicationInEuros)
{
    EXPECT_EQ(twentyEuros.amount, 20);
    EXPECT_EQ(twentyEuros.currency, "EUR");
}