import unittest
import functools #reduce func
import operator #add func
class Money:
    def __init__(self, amount, currency):
        self.amount = amount
        self.currency = currency
    def times(self, multiplier):
        return Money(self.amount * multiplier, self.currency)
    def divide(self, divisor):
        return Money(self.amount / divisor, self.currency)
    def __eq__(self, other):
        return self.amount == other.amount and self.currency == other.currency

class Portfilo:
    def __init__(self):
        self.moneys = []

    def add(self, *moneys):
        self.moneys.extend(moneys)

    def evaluate(self, currency):
        total = functools.reduce(
            operator.add, map(lambda m: m.amount, self.moneys), 0)
        return Money(total, currency)

class TestMoney(unittest.TestCase):
    def testMultiplicationInDollars(self):
        fiveDollars = Money(5,"USD")
        tenDollars = Money(10,"USD")
        self.assertEqual(tenDollars, fiveDollars.times(2))
    def testMultiplicationInEuros(self):
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