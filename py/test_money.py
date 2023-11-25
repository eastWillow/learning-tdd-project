import unittest
from money import Money
from portfolio import Portfilo

class TestMoney(unittest.TestCase):
    def testMultiplication(self):
        tenEuros = Money(10,"EUR")
        twentyEuros = Money(20, "EUR")
        self.assertEqual(twentyEuros, tenEuros.times(2))
    def testDivision(self):
        origianlMoney = Money(2500.5, "KRW")
        actualMoneyAfterDivision = origianlMoney.divide(2.5)
        expectedMoneyAfterDivision = Money(1000.2, "KRW")
        self.assertEqual(expectedMoneyAfterDivision,
                         actualMoneyAfterDivision)
    def testAddition(self):
        fiveDollars = Money(5, "USD")
        tenDollars = Money(10, "USD")
        fifteenDollars = Money(15, "USD")
        portfilo = Portfilo()
        portfilo.add(fiveDollars, tenDollars)
        self.assertEqual(fifteenDollars, portfilo.evaluate("USD"))

    def testAdditionOfDollarsAndEuros(self):
        fiveDollars = Money(5, "USD")
        tenEuros = Money(10, "EUR")
        portfilo = Portfilo()
        portfilo.add(fiveDollars, tenEuros)
        expectedValue = Money(17, "USD")
        actualValue = portfilo.evaluate("USD")
        self.assertEqual(
            expectedValue, actualValue, "%s != %s" %(expectedValue, actualValue)
        )

    def testAdditionOfDollarsAndWons(self):
        oneDollar = Money(1, "USD")
        elevenHundredWon = Money(1100, "KRW")
        portfilo = Portfilo()
        portfilo.add(oneDollar, elevenHundredWon)
        expectedValue = Money(2200, "KRW")
        actualValue = portfilo.evaluate("KRW")
        self.assertEqual(
            expectedValue, actualValue, "%s != %s" %(expectedValue, actualValue)
        )

if __name__ == '__main__':
    unittest.main()