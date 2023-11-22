package main

import (
	s "tdd/stocks"
	"testing"
)

func assertEqual(t *testing.T, expected s.Money, actual s.Money) {
	if expected != actual {
		t.Errorf("Expected %+v Got %+v", expected, actual)
	}
}

func TestMultiplaction(t *testing.T) {
	tenEuros := s.NewMoney(10, "EUR")
	actualResult := tenEuros.Times(2)
	expectedResult := s.NewMoney(20, "EUR")
	assertEqual(t, expectedResult, actualResult)
}

func TestDivision(t *testing.T) {
	origianlMoney := s.NewMoney(2500.5, "KRW")
	actualResult := origianlMoney.Divide(2.5)
	expectedResult := s.NewMoney(1000.2, "KRW")
	assertEqual(t, expectedResult, actualResult)
}

func TestAddition(t *testing.T) {
	var portfolio s.Portfolio
	var portfolioInDollars s.Money

	fiveDollars := s.NewMoney(5, "USD")
	tenDollars := s.NewMoney(10, "USD")
	fifteenDollars := s.NewMoney(15, "USD")

	portfolio = portfolio.Add(fiveDollars)
	portfolio = portfolio.Add(tenDollars)
	portfolioInDollars = portfolio.Evalute("USD")

	assertEqual(t, fifteenDollars, portfolioInDollars)
}
