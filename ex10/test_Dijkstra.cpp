#include "Dijkstra.h"
#include <iostream>

int main() {
    std::string expression = "( 1 + ( 2 + 3 ) )";
    double result = evaluate(expression);
    std::cout << expression << std::endl;
    std::cout << "Result: " << result << std::endl;

    expression = "( 54 + ( 2 * 10 ) )";
    result = evaluate(expression);
    std::cout << expression << std::endl;
    std::cout << "Result: " << result << std::endl;

    std::cout<<"please input fully parenthesized arithmetic."<<std::endl;
    std::cout<<"caution! It will not be executed unless you enter a space between the tokens."<<std::endl;
    //example "( 2 + ( 34 / 2 ) )"
    std::getline(std::cin, expression);
    result = evaluate(expression);
    std::cout << expression << std::endl;
    std::cout << "Result: " << result << std::endl;

    return 0;
}