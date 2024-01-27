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