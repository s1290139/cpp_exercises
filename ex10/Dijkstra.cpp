#include "Dijkstra.h"
#include <iostream>
#include <stack>
#include <sstream>
#include <string>

double evaluate(const std::string& expression) {
    std::stack<double> operands;
    std::stack<char> operators;
    std::istringstream input(expression);
    std::string token;

    while (input >> token) {
        if (token == "(") {
            // Ignore left parenthesis
        } else if (token == "+" || token == "-" || token == "*" || token == "/") {
            operators.push(token[0]);
        } else if (token == ")") {
            char op = operators.top();
            operators.pop();

            double operand2 = operands.top();
            operands.pop();

            double operand1 = operands.top();
            operands.pop();

            double result;

            if (op == '+') {
                result = operand1 + operand2;
            } else if (op == '-') {
                result = operand1 - operand2;
            } else if (op == '*') {
                result = operand1 * operand2;
            } else if (op == '/') {
                result = operand1 / operand2;
            }

            operands.push(result);
        } else {
            double operand = std::stod(token);
            operands.push(operand);
        }
    }

    return operands.top();
}