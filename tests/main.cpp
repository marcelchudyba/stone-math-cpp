#include <iostream>

#include "Evaluator.h"
#include "../include/Parser.h"
#include "Lexer.h"
#include "Parser.h"
#include "StoneMath.h"

int main() {
    StoneMath::StoneMath math = StoneMath::StoneMath();

    std::cout << math.GetResult("sin(2 x)");
}
