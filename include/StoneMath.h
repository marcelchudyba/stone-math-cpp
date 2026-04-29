#pragma once
#include <string>

#include "Evaluator.h"
#include "../include/Parser.h"
#include "Lexer.h"
#include "Parser.h"
#include "StoneMath.h"

namespace StoneMath {
    class StoneMath {
        public:
            StoneMath();
            double GetResult(std::string to_calculate, const double& x);
    };
}
