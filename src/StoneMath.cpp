#include "StoneMath.h"

#include <iostream>

StoneMath::StoneMath::StoneMath(){};

double StoneMath::StoneMath::GetResult(std::string equation,const double& x) {

    Lexer lexer = Lexer(equation);

    std::vector<Token> tokenized = lexer.Tokenize();

    Parser parser = Parser(tokenized);

    std::vector<Token> onp_notation = parser.Parse();

    Evaluator evaluator = Evaluator(onp_notation);
    double output = evaluator.Evaluate(x);

    return output;
}

