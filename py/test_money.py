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

if __name__ == '__main__':
    unittest.main()