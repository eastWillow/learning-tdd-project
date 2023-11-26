const assert = require('assert');
const Money = require('./Money');
const Portfolio = require('./Portfoilo');
const exp = require('constants');

class MoneyTest{
    testMultiplication()
    {
        let tenEuros = new Money(10, "EUR")
        let twentyEuros = new Money(20, "EUR")
        assert.deepStrictEqual(tenEuros.times(2), twentyEuros)        
    }
    testDivision()
    {
        let originalMoney = new Money(2500.5, "KRW")
        let actualMoneyAfterDivision = originalMoney.divide(2.5)
        let expectedMoneyAfterDivision = new Money(1000.2, "KRW")
        assert.deepStrictEqual(actualMoneyAfterDivision, expectedMoneyAfterDivision)        
    }

    testAddition()
    {
        let fiveDollars = new Money(5, "USD");
        let tenDollars = new Money(10, "USD");
        let fifteenDollars = new Money(15, "USD");
        let portfolio = new Portfolio();
        portfolio.add(fiveDollars, tenDollars);
        assert.deepStrictEqual(portfolio.evaluate("USD"), fifteenDollars);
    }

    testAdditionOfDollarsAndEuros(){
        let fiveDollars = new Money(5, "USD");
        let tenEuros = new Money(10, "EUR");
        let portfolio = new Portfolio();

        portfolio.add(fiveDollars, tenEuros);

        let expectedValue = new Money(17, "USD");
        assert.deepStrictEqual(portfolio.evaluate("USD"), expectedValue);
    }

    testAdditionOfDollarsAndWons(){
        let oneDollar = new Money(1, "USD");
        let elevenHundredWon = new Money(1100, "KRW");
        let portfolio = new Portfolio();

        portfolio.add(oneDollar, elevenHundredWon);
        let expectedValue = new Money(2200, "KRW");
        assert.deepStrictEqual(portfolio.evaluate("KRW"), expectedValue);
    }

    testAdditionWithMultipleMissingExchangeRates(){
        let oneDollar = new Money(1, "USD")
        let oneEuro = new Money(1, "EUR");
        let oneWon = new Money(1, "KRW");
        let portfolio = new Portfolio();
        portfolio.add(oneDollar, oneEuro, oneWon);
        let expectedError = new Error(
            "Missing exchange rate(s):[USD->Kalganid,EUR->Kalganid,KRW->Kalganid]");
        assert.throws(function() {portfolio.evaluate("Kalganid")}, expectedError);
    }

    getAllTestMethods(){
        let moneyProtype = MoneyTest.prototype;
        let allProps = Object.getOwnPropertyNames(moneyProtype);
        let testMethods = allProps.filter(p => {
            return typeof moneyProtype[p] === 'function' && p.startsWith("test");
        });
        return testMethods;
    }

    runAlltests()
    {
        let testMethods = this.getAllTestMethods();
        testMethods.forEach(m =>{
            console.log("Running: %s()", m);
            let method = Reflect.get(this, m);
            try{
                Reflect.apply(method, this, []);
            }catch(e){
                if(e instanceof assert.AssertionError){
                    console.log(e);
                }else{
                    throw e;
                }
            }
        });
    }
}

new MoneyTest().runAlltests();