#include "../include/Parser.h"
#include <vector>

StoneMath::Parser::Parser(const std::vector<Token>& tokens) : input_tokens(tokens) {};

int StoneMath::Parser::GetPrecedence(TokenType type) {
    if(type == TokenType::Plus || type == TokenType::Minus) {
        return 1;
    }
    if(type == TokenType::Divide || type == TokenType::Multiply) {
        return 2;
    }
    if(type == TokenType::Power) {
        return 3;
    }
    return 0;
}


std::vector<StoneMath::Token> StoneMath::Parser::Parse() {

    int i = 0;
    for (auto token: input_tokens) {
        if(token.type == TokenType::Number || token.type == TokenType::Variable) {
            output_queue.push_back(token);
        }
        else if(token.type == TokenType::EOF_Type) {
            //for the end of file we are throwing everything from the stack to output_queue
            while(!operator_stack.empty()) {
                Token top_stack = operator_stack.top();
                operator_stack.pop();
                output_queue.push_back(top_stack);
            }
        }
        else if(token.type == TokenType::RParen) {
                //for right Paren we need to look on the stack and throw everything till the L_Paren
                while(operator_stack.top().type != TokenType::LParen) {
                    Token top_stack = operator_stack.top();
                    operator_stack.pop();
                    output_queue.push_back(top_stack);
                }
                operator_stack.pop();

                //we are checking if its a function before parens if it its we throw it to the queue
                if(!operator_stack.empty() && operator_stack.top().type == TokenType::Function) {
                    Token top_stack = operator_stack.top();
                    operator_stack.pop();
                    output_queue.push_back(top_stack);
                }
            }
        else if(token.type == TokenType::LParen || token.type == TokenType::Function) {
            //with no hesitation we always push LParen and Function type to the stack
            operator_stack.push(token);
        }
        else {

            //this is for the negative numbers in the start of eqaution
            if(i == 0 && token.type == TokenType::Minus ) {
                output_queue.push_back(Token{TokenType::Number, "0"});
            }

            //this is for a negative number we are only accepting those in betweeen brackets
            if(!operator_stack.empty() && operator_stack.top().type == TokenType::LParen && token.type == TokenType::Minus) {
                output_queue.push_back(Token{TokenType::Number, "0"});
            }


            //there are going operators
            if(!operator_stack.empty() && GetPrecedence(operator_stack.top().type) > GetPrecedence(token.type)) {
                Token top = operator_stack.top();
                operator_stack.pop();
                output_queue.push_back(top);
                operator_stack.push(token);
            }
            else{
            operator_stack.push(token);
            }
        }
        i++;
    }
    return output_queue;
}

