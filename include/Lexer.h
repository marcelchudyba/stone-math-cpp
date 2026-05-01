//
// Created by XXX on 25.04.2026.
//

#pragma once
#include <vector>

#include "TokenType.h"

namespace StoneMath {
    class Lexer {
        std::string text;
        int position;
        char currentChar;


    public:
        Lexer(const std::string& text);
        std::vector<Token> Tokenize();

    };
}

