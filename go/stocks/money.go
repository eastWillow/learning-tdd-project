package stocks

type Money struct {
	amount   float64
	currency string
}

func NewMoney(amount float64, currency string) Money {
	return Money{amount, currency}
}
func (m Money) Times(multiplier int) Money {
	return Money{amount: m.amount * float64(multiplier), currency: m.currency}
}

func (m Money) Divide(divisor float64) Money {
	return Money{amount: m.amount / float64(divisor), currency: m.currency}
}
