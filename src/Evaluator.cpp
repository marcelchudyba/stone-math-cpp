//
// Created by XXX on 25.04.2026.
//
#include "Evaluator.h"


StoneMath::Evaluator::Evaluator(std::vector<Token>& tokens) {
    this->rpn_tokens = tokens;
}
double StoneMath::Evaluator::Operation_Type(TokenType type, const double& left,const double& right) {
    switch (type) {
        case TokenType::Multiply:
            return left*right;
        case TokenType::Divide:

            // if(right == 0) {
                //in the future
                    // }
                        return left/right;
        case TokenType::Minus:
            return left-right;
        case TokenType::Plus:
            return left+right;
        case TokenType::Power:
            return pow(left,right);
        default:
            break;
    }
}

double StoneMath::Evaluator::Evaluate(const double& x) {
    for(int i = 0; i < this->rpn_tokens.size(); i++) {
        if(rpn_tokens[i].type == TokenType::Number) {
            double current_number = std::stod(rpn_tokens[i].value);
            numbers_stack.push(current_number);
        }
        else {
            double right = numbers_stack.top();
            numbers_stack.pop();
            double left = numbers_stack.top();
            numbers_stack.pop();

            TokenType current_operator = rpn_tokens[i].type;

            double output = Operation_Type(current_operator, left, right);

            numbers_stack.push(output);
        }
    }

    return numbers_stack.top();


}


