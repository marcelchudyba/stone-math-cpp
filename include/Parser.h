//
// Created by XXX on 25.04.2026.
//


#pragma once
#include <stack>
#include <queue>

#include "TokenType.h"


namespace StoneMath {
    class Parser {
        private:

        std::vector<Token> input_tokens;

        std::stack<Token> operator_stack;

        //queue with onp notation
        std::vector<Token> output_queue;

        int GetPrecedence(TokenType type);

    public:
        Parser(const std::vector<Token>& tokens);
        std::vector<Token> Parse();
    };
}
