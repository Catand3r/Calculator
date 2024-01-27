#include <iostream>
#include <string>
#include "../include/Calculator.h"

int main()
{
    Calculator<int> calculator;
    std::cout << "Jakie chcesz wykonac dzialanie? \n";
    std::string userInput;
    std::cin >> userInput;
    try
    {
        std::cout << calculator.execute(userInput);
    }
    catch (std::invalid_argument e)
    {
        std::cout << e.what();
    }
}

/*
Stworzyć klasę Calculator (tylko liczby całkowite), która:
1. Będzie miała publiczną metodę int Execute(std::string);
Metoda ta powinna parsować stringa wejściowego i zwracać wynik.
Przykład:
int result = calculator.execute("3+4"); // result = 7
+,-,/,*
2. Utworzyć jako osobny pliki (Calculator.h, Calculator.cpp)
3. W main.cpp tylko funkcja main()

w pliku h
class Calculator
{

};


w pliku cpp

Calculator::Calculator()
{

}

int Calculator::execute(std::string input)
{
    // do sth ...
    return result;
}


*/