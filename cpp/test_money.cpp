#include "gtest/gtest.h"
#include "money.h"
#include "portfolio.h"

TEST(TestMoney, TestMultiplication)
{
    auto tenEuros = Money(10, "EUR");
    auto twentyEuros = tenEuros.times(2);

    EXPECT_EQ(twentyEuros.amount, 20);
    EXPECT_EQ(twentyEuros.currency, "EUR");
}


TEST(TestMoney, TestDivisions)
{
    auto orignalMoney = Money(2500.5,"KRW");
    auto actualMoneyAfterDivision = orignalMoney.divide(2.5);
    auto expectedMoneyAdterDivision = Money(1000.2, "KRW");

    EXPECT_EQ(actualMoneyAfterDivision, expectedMoneyAdterDivision);
}


TEST(TestMoney, TestAddition)
{
    auto fiveDollars = Money(5,"USD");
    auto tenDollars = fiveDollars.times(2);
    auto fifteenDollars = Money(15, "USD");
    auto portfolio = Portfolio();

    portfolio.add(fiveDollars, tenDollars);

    EXPECT_EQ(portfolio.evaluate("USD"), fifteenDollars);
}

TEST(TestMoney, TestAdditionOfDollarsAndEuros)
{
    auto fiveDollars = Money(5,"USD");
    auto tenEuros = Money(10, "EUR");
    auto portfolio = Portfolio();

    portfolio.add(fiveDollars, tenEuros);
    auto actualValue = portfolio.evaluate("USD");
    auto expectedValue = Money(17, "USD");

    EXPECT_EQ(actualValue, expectedValue);
}