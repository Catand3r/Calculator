#include <iostream>
#include <algorithm>
#include <string>
#include <exception>
#include <cmath>
#include "../include/Calculator.h"

int Calculator::execute(std::string userInput) // ""
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
    std::copy(userInput.begin(), it, number1.begin()); // it == * // number1 == 4
    int number1int = std::stoi(number1);               // "k+2"

    std::string number2;
    std::copy(it + 1, userInput.end(), number2.begin()); // number2 == *2
    int number2int = std::stoi(number2);

    if (operation == '-')
    {
        return number1int - number2int;
    }
    else if (operation == '+')
    {
        return number1int + number2int;
    }
    else if (operation == '*')
    {
        return number1int * number2int;
    }
    else if (operation == '/')
    {
        if (number2int != 0)
        {
            return number1int / number2int;
        }
        else
        {
            throw InvalidInput("Can't divide by 0");
        }
    }
    else if (operation == '^')
    {
        return std::pow(number1int, number2int);
    }
    else
    {
        throw InvalidInput("Unknown operation");
        //  return -1; // czy to jest wynik?? "3-4" , "3?4" -> -1
    }
}