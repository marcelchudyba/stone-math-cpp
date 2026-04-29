#include "StoneMath.h"

#include <iostream>

StoneMath::StoneMath::StoneMath(){};

double StoneMath::StoneMath::GetResult(std::string equation) {

    Lexer lexer = Lexer("x + 2");

    std::vector<Token> tokenized = lexer.Tokenize();

    Parser parser = Parser(tokenized);

    std::vector<Token> onp_notation = parser.Parse();

    Evaluator evaluator = Evaluator(onp_notation);
    double output = evaluator.Evaluate(4);

    return output;
}

