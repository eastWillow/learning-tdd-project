#include "gtest/gtest.h"
#include "money.h"
#include "portfolio.h"

auto tenEuros = Money(10, "EUR");
auto twentyEuros = tenEuros.times(2);

TEST(TestMoney, TestMultiplication)
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

auto fiveDollars = Money(5,"USD");
auto tenDollars = fiveDollars.times(2);
auto fifteenDollars = Money(15, "USD");
auto portfolio = Portfolio();

TEST(TestMoney, TestAddition)
{
    portfolio.add(fiveDollars, tenDollars);

    EXPECT_EQ(portfolio.evaluate("USD"), fifteenDollars);
}