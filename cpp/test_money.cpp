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


TEST(TestPortfolio, TestAddition)
{
    auto fiveDollars = Money(5,"USD");
    auto tenDollars = fiveDollars.times(2);
    auto fifteenDollars = Money(15, "USD");
    auto portfolio = Portfolio();

    portfolio.add(fiveDollars);
    portfolio.add(tenDollars);

    EXPECT_EQ(portfolio.evaluate("USD"), fifteenDollars);
}

TEST(TestPortfolio, TestAdditionOfDollarsAndEuros)
{
    auto fiveDollars = Money(5,"USD");
    auto tenEuros = Money(10, "EUR");
    auto portfolio = Portfolio();

    portfolio.add(fiveDollars);
    portfolio.add(tenEuros);

    auto actualValue = portfolio.evaluate("USD");
    auto expectedValue = Money(17, "USD");

    EXPECT_EQ(actualValue, expectedValue);
}

TEST(TestPortfolio, TestAdditionOfDollarsAndWons)
{
    auto oneDollar = Money(1, "USD");
    auto elevenHundredWons = Money(1100, "KRW");
    auto portfolio = Portfolio();

    portfolio.add(oneDollar);
    portfolio.add(elevenHundredWons);

    auto actualValue = portfolio.evaluate("KRW");
    auto expectedValue = Money(2200, "KRW");

    EXPECT_EQ(actualValue, expectedValue);
}

TEST(TestPortfolio, TestAdditionWithMultipleMissingExchangeRates)
{
    auto oneDollar = Money(1, "USD");
    auto oneEuro = Money(1, "EUR");
    auto oneWon = Money(1, "KRW");
    auto portfolio = Portfolio();

    portfolio.add(oneDollar);
    portfolio.add(oneEuro);
    portfolio.add(oneWon);

    EXPECT_THROW(portfolio.evaluate("Kalganid"), std::out_of_range);

    try {
        portfolio.evaluate("Kalganid");
    } catch (const std::out_of_range& ex) {
        EXPECT_STREQ(ex.what(), "Missing exchange rate(s):[USD->Kalganid,EUR->Kalganid,KRW->Kalganid,]");
    }
}