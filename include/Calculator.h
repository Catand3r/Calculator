#include <exception>
#include <iostream>
#include <algorithm>
#include <string>
#include <exception>
#include <cmath>
#include <iterator>
#include <type_traits>

class InvalidInput : public std::exception
{
public:
    InvalidInput(std::string msg) : message(msg) {}
    ~InvalidInput() = default;
    const char *what() { return message.c_str(); }

private:
    std::string message;
};

template <typename T>
class Calculator
{
public:
    T execute(std::string) const;

private:
    T performOperation(char, T, T) const;
    T getNumberFromString(std::string input) const;
};

template <typename T>
T Calculator<T>::execute(std::string userInput) const
{
    if (userInput.empty())
    {
        throw InvalidInput("No input");
    }
    std::string operators = "+-*/^";
    char operation;
    auto it = std::find_first_of(userInput.begin() + 1, userInput.end(), operators.begin(), operators.end());
    if (it != userInput.end())
    {
        operation = *it;
    }
    else
    {
        throw InvalidInput("No operation");
    }

    std::string number1;
    std::copy(userInput.begin(), it, std::back_inserter(number1));
    std::string number2;
    std::copy(it + 1, userInput.end(), std::back_inserter(number2));
    return performOperation(operation, getNumberFromString(number1), getNumberFromString(number2));
}

template <typename T>
T Calculator<T>::performOperation(const char operation, T firstNumber, T secondNumber) const
{
    if (operation == '-')
    {
        return firstNumber - secondNumber;
    }
    else if (operation == '+')
    {
        return firstNumber + secondNumber;
    }
    else if (operation == '*')
    {
        return firstNumber * secondNumber;
    }
    else if (operation == '/')
    {
        if (secondNumber != 0)
        {
            return firstNumber / secondNumber;
        }
        else
        {
            throw InvalidInput("Can't divide by 0");
        }
    }
    else if (operation == '^')
    {
        return std::pow(firstNumber, secondNumber);
    }
    else
    {
        throw InvalidInput("Unknown operation");
    }
}

template <typename T>
T Calculator<T>::getNumberFromString(std::string input) const
{
    if (std::is_floating_point<T>::value)
    {
        return static_cast<T>(std::stold(input));
    }
    else
    {
        return static_cast<T>(std::stoll(input));
    }
}
