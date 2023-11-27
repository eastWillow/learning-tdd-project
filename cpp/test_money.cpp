#include "gtest/gtest.h"
#include "money.h"
#include "portfolio.h"
#include "bank.h"

class TestPortfolio : public ::testing::Test {
public:
    Bank bank;

    void SetUp() override {
        bank = Bank();
        bank.addExchangeRate("EUR", "USD", 1.2);
        bank.addExchangeRate("USD", "KRW", 1100);
    }
};

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


TEST_F(TestPortfolio, TestAddition)
{
    auto fiveDollars = Money(5,"USD");
    auto tenDollars = fiveDollars.times(2);
    auto fifteenDollars = Money(15, "USD");
    auto portfolio = Portfolio();

    portfolio.add(fiveDollars);
    portfolio.add(tenDollars);

    EXPECT_EQ(portfolio.evaluate(bank, "USD"), fifteenDollars);
}

TEST_F(TestPortfolio, TestAdditionOfDollarsAndEuros)
{
    auto fiveDollars = Money(5,"USD");
    auto tenEuros = Money(10, "EUR");
    auto portfolio = Portfolio();

    portfolio.add(fiveDollars);
    portfolio.add(tenEuros);

    auto actualValue = portfolio.evaluate(bank, "USD");
    auto expectedValue = Money(17, "USD");

    EXPECT_EQ(actualValue, expectedValue);
}

TEST_F(TestPortfolio, TestAdditionOfDollarsAndWons)
{
    auto oneDollar = Money(1, "USD");
    auto elevenHundredWons = Money(1100, "KRW");
    auto portfolio = Portfolio();

    portfolio.add(oneDollar);
    portfolio.add(elevenHundredWons);

    auto actualValue = portfolio.evaluate(bank, "KRW");
    auto expectedValue = Money(2200, "KRW");

    EXPECT_EQ(actualValue, expectedValue);
}

TEST_F(TestPortfolio, TestAdditionWithMultipleMissingExchangeRates)
{
    auto oneDollar = Money(1, "USD");
    auto oneEuro = Money(1, "EUR");
    auto oneWon = Money(1, "KRW");
    auto portfolio = Portfolio();

    portfolio.add(oneDollar);
    portfolio.add(oneEuro);
    portfolio.add(oneWon);

    EXPECT_THROW(portfolio.evaluate(bank, "Kalganid"), std::out_of_range);

    try {
        portfolio.evaluate(bank, "Kalganid");
    } catch (const std::out_of_range& ex) {
        EXPECT_STREQ(ex.what(), "Missing exchange rate(s):[USD->Kalganid,EUR->Kalganid,KRW->Kalganid,]");
    }
}

TEST(TestBank, TestConversion)
{
    auto bank = Bank();
    bank.addExchangeRate("EUR", "USD", 1.2);
    auto tenEuros = Money(10, "EUR");
    
    EXPECT_EQ(bank.convert(tenEuros, "USD"), Money(12, "USD"));
}

TEST(TestBank, TestConversionWithMissingExchangeRate)
{
    auto bank = Bank();
    auto tenEuros = Money(10, "EUR");

    try {
        bank.convert(tenEuros, "Kalganid");
    } catch (const std::out_of_range& ex) {
        EXPECT_STREQ(ex.what(), "EUR->Kalganid");
    }
}