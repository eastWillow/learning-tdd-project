#include "gtest/gtest.h"

class Dollar{
    public:
    int amount;
    Dollar(int amount){
        this->amount = amount;
    }
    auto times(int multiplier){
        return Dollar(this->amount * multiplier);
    }
};

auto fiver = Dollar(5);
auto tenner = fiver.times(2);

TEST(testMath, myTest)
{
    EXPECT_EQ(tenner.amount, 10); 
}