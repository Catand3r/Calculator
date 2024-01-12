#include <exception>

class InvalidInput : public std::exception
{
public:
    InvalidInput(std::string msg) : message(msg) {}
    ~InvalidInput() = default;
    const char *what() { return message.c_str(); }

private:
    std::string message;
};

class Calculator
{
public:
    int execute(std::string);
};