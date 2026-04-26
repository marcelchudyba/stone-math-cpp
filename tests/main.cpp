#include <iostream>

#include "Lexer.h"


int main() {
    StoneMath::Lexer lexer = StoneMath::Lexer("2(x+2)^2(x + 2)(x + 3)sin + 2(y)");

    std::vector<StoneMath::Token> tokenized = lexer.Tokenize();

    for (auto value: tokenized) {
        std::cout << value.value << std::endl;
    }

}
