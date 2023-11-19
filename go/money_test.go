package main

import (
	"testing"
)

type Money struct {
	amount   int
	currency string
}

func (m Money) Times(multiplier int) Money {
	return Money{amount: m.amount * multiplier, currency: m.currency}
}

func TestMultiplactionInDollars(t *testing.T) {
	fiver := Money{amount: 5, currency: "USD"}
	tenner := fiver.Times(2)
	if tenner.amount != 10 {
		t.Errorf("Expected 10, got : [%d]", tenner.amount)
	}
}

func TestMultiplactionInEuros(t *testing.T) {
	tenEuros := Money{amount: 10, currency: "EUR"}
	twentyEuros := tenEuros.Times(2)
	if twentyEuros.amount != 20 {
		t.Errorf("Expected 20, got:[%d]", twentyEuros.amount)
	}
	if twentyEuros.currency != "EUR" {
		t.Errorf("Expected EUR, got:[%s]", twentyEuros.currency)
	}
}
