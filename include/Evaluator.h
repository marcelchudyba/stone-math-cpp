//
// Created by XXX on 25.04.2026.
//

#pragma once
#include <stack>
#include <vector>

#include "TokenType.h"

namespace StoneMath {
    class Evaluator {
    private:
        std::vector<Token> rpn_tokens;
        std::stack<double> numbers_stack;
        double output_value;

        double Operation_Type(TokenType type, const double& left,const double& right);
    public:
        Evaluator(std::vector<Token>& tokens);

        double Evaluate(const double& x);
    };
}
