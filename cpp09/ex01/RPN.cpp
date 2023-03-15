#include "RPN.hpp"

RPN::RPN() {}
RPN::RPN(const RPN &other) { *this = other; }
RPN &RPN::operator=(const RPN &other) { return *this; }
RPN::~RPN() {}

bool RPN::isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int RPN::performOperation(char op, int a, int b) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (b == 0) throw std::runtime_error("Error: Division by zero.");
            return a / b;
        default: throw std::runtime_error("Error: Invalid operator.");
    }
}

int RPN::evaluate(const std::string &expression) {
    while (!s.empty()) s.pop(); // Clear the stack before evaluating a new expression

    for (size_t i = 0; i < expression.size(); ++i) {
        if (isdigit(expression[i])) {
            int num = expression[i] - '0';
            if (num >= 10) throw std::runtime_error("Error: Number must be less than 10.");
            s.push(num);
        } else if (isOperator(expression[i])) {
            if (s.size() < 2) throw std::runtime_error("Error: Invalid expression.");
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            s.push(performOperation(expression[i], a, b));
        }
    }

    if (s.size() != 1) throw std::runtime_error("Error: Invalid expression.");
    return s.top();
}
