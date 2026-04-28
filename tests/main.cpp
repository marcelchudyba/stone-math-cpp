#include <iostream>

#include "Evaluator.h"
#include "../include/Parser.h"
#include "Lexer.h"
#include "Parser.h"
#include "StoneMath.h"

int main() {
    StoneMath::Lexer lexer = StoneMath::Lexer("sqrt ( x ^ 2 + 9 ) * 2 - sin ( x ) / tan ( x )");

    std::vector<StoneMath::Token> tokenized = lexer.Tokenize();

    std::cout << "tokenized: " << std::endl;

    for (auto value: tokenized) {
        std::cout << value.value << " ";
    }
    std::cout << std::endl;

    std::cout << "onp: " << std::endl;

    StoneMath::Parser parser = StoneMath::Parser(tokenized);

    std::vector<StoneMath::Token> onp_notation = parser.Parse();
    for (auto value: onp_notation) {
        std::cout << value.value << " ";
    }
    StoneMath::Evaluator evaluator = StoneMath::Evaluator(onp_notation);
    double output = evaluator.Evaluate(4);

    std::cout << std::endl <<  "equation answer: " << std::endl;
    std::cout << output << std::endl;
}
