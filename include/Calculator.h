#include <exception>
#include <iostream>
#include <algorithm>
#include <string>
#include <exception>
#include <cmath>

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
    T performOperation(char, int, int) const;
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
    std::copy(userInput.begin(), it, number1.begin());
    int number1int = std::stoi(number1);

    std::string number2;
    std::copy(it + 1, userInput.end(), number2.begin());
    int number2int = std::stoi(number2);

    return performOperation(operation, number1int, number2int);
}

template <typename T>
T Calculator<T>::performOperation(const char operation, int firstNumber, int secondNumber) const
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