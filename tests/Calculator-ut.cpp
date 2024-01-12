#include "gtest/gtest.h"
#include "../include/Calculator.h"

TEST(CalculatorTests, AlwaysTrue)
{
    EXPECT_EQ(true, true);
}

TEST(CalculatorTests, Given3Plus4WhenExecuteIsCalledThenReturn7)
{
    Calculator calc;
    EXPECT_EQ(calc.execute("3+4"), 7);
}

TEST(CalculatorTests, Given4Times2WhenExecuteIsCalledThenReturn8)
{
    Calculator calc;
    EXPECT_EQ(calc.execute("4*2"), 8);
}

TEST(CalculatorTest, Given4Minus2WhenExecuteIsCalledThenReturn2)
{
    Calculator calc;
    EXPECT_EQ(calc.execute("4-2"), 2);
}

TEST(CalculatorTest, Given4DividedBy2WhenExecuteIsCalledThenReturn2)
{
    Calculator calc;
    EXPECT_EQ(calc.execute("4/2"), 2);
}

TEST(CalculatorTest, Given4DividedBy0WhenExecuteIsCalledThenThrowException)
{
    Calculator calc;
    EXPECT_THROW(calc.execute("4/0"), InvalidInput);
}

TEST(CalculatorTest, GivenMinus4Plus1WhenExecuteIsCalledThenReturnMinus3)
{
    Calculator calc;
    EXPECT_EQ(calc.execute("-4+1"), -3);
}

TEST(CalculatorTest, GivenEmptyInputWhenExecuteIsCalledThenThrowException)
{
    Calculator calc;
    EXPECT_THROW(calc.execute(""), InvalidInput);
}

TEST(CalculatorTest, GivenMinus10MinusMinus20WhenExecuteIsCalledThenReturn10)
{
    Calculator calc;
    EXPECT_EQ(calc.execute("-10--20"), 10);
}

TEST(CalculatorTest, GivenInputWithoutOperatorWhenExecuteIsCalledThenThrowException)
{
    Calculator calc;
    EXPECT_THROW(calc.execute("3%2"), InvalidInput);
}

TEST(CalculatorTest, GivenKPlus2WhenExecuteIsCalledThenThrowException)
{
    Calculator calc;
    EXPECT_THROW(calc.execute("k+2"), std::invalid_argument);
}

TEST(CalculatorTest, Given2PlusKWhenExecuteIsCalledThenThrowException)
{
    Calculator calc;
    EXPECT_THROW(calc.execute("2+k"), std::invalid_argument);
}