package main

import (
	"testing"
)

type Money struct {
	amount   float64
	currency string
}

func (m Money) Times(multiplier int) Money {
	return Money{amount: m.amount * float64(multiplier), currency: m.currency}
}

func (m Money) Divide(divisor int) Money {
	return Money{amount: m.amount / float64(divisor), currency: m.currency}
}

func TestMultiplactionInDollars(t *testing.T) {
	fiver := Money{amount: 5, currency: "USD"}
	actualResult := fiver.Times(2)
	expectedResult := Money{amount: 10, currency: "USD"}
	if expectedResult != actualResult {
		t.Errorf("Expected [%+v], got : [%+v]", expectedResult, actualResult)
	}
}

func TestMultiplactionInEuros(t *testing.T) {
	tenEuros := Money{amount: 10, currency: "EUR"}
	actualResult := tenEuros.Times(2)
	expectedResult := Money{amount: 20, currency: "EUR"}
	if expectedResult != actualResult {
		t.Errorf("Expected [%+v], got : [%+v]", expectedResult, actualResult)
	}
}

func TestDivision(t *testing.T) {
	origianlMoney := Money{amount: 4002, currency: "KRW"}
	actualMoneyAfterDivision := origianlMoney.Divide(4)
	expectedMoneyAfterDivision := Money{amount: 1000.5, currency: "KRW"}
	if expectedMoneyAfterDivision != actualMoneyAfterDivision {
		t.Errorf("Expected %+v Got %+v",
			expectedMoneyAfterDivision, actualMoneyAfterDivision)
	}
}
