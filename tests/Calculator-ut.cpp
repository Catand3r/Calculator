#include "gtest/gtest.h"
#include "../include/Calculator.h"

TEST(CalculatorTests, AlwaysTrue)
{
    EXPECT_EQ(true, true);
}

TEST(CalculatorTests, Given3Plus4WhenExecuteIsCalledThenReturn7)
{
    Calculator<int> calc;
    EXPECT_EQ(calc.execute("3+4"), 7);
}

TEST(CalculatorTests, Given4Times2WhenExecuteIsCalledThenReturn8)
{
    Calculator<int> calc;
    EXPECT_EQ(calc.execute("4*2"), 8);
}

TEST(CalculatorTest, Given4Minus2WhenExecuteIsCalledThenReturn2)
{
    Calculator<int> calc;
    EXPECT_EQ(calc.execute("4-2"), 2);
}

TEST(CalculatorTest, Given4DividedBy2WhenExecuteIsCalledThenReturn2)
{
    Calculator<int> calc;
    EXPECT_EQ(calc.execute("4/2"), 2);
}

TEST(CalculatorTest, Given4DividedBy0WhenExecuteIsCalledThenThrowException)
{
    Calculator<int> calc;
    EXPECT_THROW(calc.execute("4/0"), InvalidInput);
}

TEST(CalculatorTest, GivenMinus4Plus1WhenExecuteIsCalledThenReturnMinus3)
{
    Calculator<int> calc;
    EXPECT_EQ(calc.execute("-4+1"), -3);
}

TEST(CalculatorTest, GivenEmptyInputWhenExecuteIsCalledThenThrowException)
{
    Calculator<int> calc;
    EXPECT_THROW(calc.execute(""), InvalidInput);
}

TEST(CalculatorTest, GivenMinus10MinusMinus20WhenExecuteIsCalledThenReturn10)
{
    Calculator<int> calc;
    EXPECT_EQ(calc.execute("-10--20"), 10);
}

TEST(CalculatorTest, GivenInputWithoutOperatorWhenExecuteIsCalledThenThrowException)
{
    Calculator<int> calc;
    EXPECT_THROW(calc.execute("3%2"), InvalidInput);
}

TEST(CalculatorTest, GivenKPlus2WhenExecuteIsCalledThenThrowException)
{
    Calculator<int> calc;
    EXPECT_THROW(calc.execute("k+2"), std::invalid_argument);
}

TEST(CalculatorTest, Given2PlusKWhenExecuteIsCalledThenThrowException)
{
    Calculator<int> calc;
    EXPECT_THROW(calc.execute("2+k"), std::invalid_argument);
}

TEST(CalculatorTest, Given2RaisedToThePowerOf2WhenExecuteIsCalleThenReturn4)
{
    Calculator<int> calc;
    EXPECT_EQ(calc.execute("2^2"), 4);
}

TEST(CalculatorTest, Given10000000Plus10000000WhenExecuteIsCalledThenReturn20000000)
{
    Calculator<long long> calc;
    EXPECT_EQ(calc.execute("10000000+10000000"), 20000000);
}

TEST(CalculatorTest, Given20000000Minus10000000WhenExecuteIsCalledThenReturn10000000)
{
    Calculator<long long> calc;
    EXPECT_EQ(calc.execute("20000000-10000000"), 10000000);
}

TEST(CalculatorTest, Given1000000Times1000000WhenExecuteIsCalledThenReturn1000000000000)
{
    Calculator<long long> calc;
    EXPECT_EQ(calc.execute("10000*10000"), 100000000);
}

TEST(CalculatorTest, Given1000000000000DividedBy1000000WhenExecuteIsCalledThenReturn1000000)
{
    Calculator<long long> calc;
    EXPECT_EQ(calc.execute("100000000/10000"), 10000);
}

TEST(CalculatorTest, Given10ToThePowerOf11WhenExecuteIsCalledThenReturn100000000000)
{
    Calculator<long long> calc;
    EXPECT_EQ(calc.execute("10^11"), 100000000000);
}

TEST(CalculatorTest, Given2AndAHalfPlus3AndAHalfWhenExecuteIsCalledThenRetrun6)
{
    Calculator<double> calc;
    EXPECT_EQ(calc.execute("2.5+3.5"), 6);
}