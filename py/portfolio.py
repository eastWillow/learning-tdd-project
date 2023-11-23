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
            operator.add, map(lambda m: m.amount, self.moneys), 0)
        return Money(total, currency)
