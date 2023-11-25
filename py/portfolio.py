import functools #reduce func
import operator #add func
from money import Money

class Portfilo:
    def __init__(self):
        self.moneys = []

    def add(self, *moneys):
        self.moneys.extend(moneys)

    def evaluate(self, currency):
        total = functools.reduce(
            operator.add, map(lambda m: self.convert(m,currency), self.moneys), 0)
        return Money(total, currency)
    
    def convert(self, aMoney, aCurrency):
        exchangeRates = {'EUR->USD':1.2, 'USD->KRW':1100}
        if aMoney.currency == aCurrency:
            return aMoney.amount
        else:
            key = aMoney.currency + '->' + aCurrency
            return aMoney.amount * exchangeRates[key]
