#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <iostream>

class RPN {
public:
    RPN();
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);
    ~RPN();

    int evaluate(const std::string &expression);

private:
    bool isOperator(char c);
    int performOperation(char op, int a, int b);
    std::stack<int> s;
};

#endif // RPN_HPP
