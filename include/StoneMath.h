#pragma once
#include <string>

#include "Evaluator.h"
#include "../include/Parser.h"
#include "Lexer.h"
#include "Parser.h"
#include "StoneMath.h"

namespace StoneMath {
    class StoneMath {
            std::string expr;
            std::vector<Token> tokenized_expr;
            std::vector<Token> parsed_expr;

        public:
            StoneMath(const std::string& expr);

            std::vector<Token> GetTokenizedExpr();
            std::vector<Token> GetParsedExpr();

            double Evaluate(const double& x);
    };
}
