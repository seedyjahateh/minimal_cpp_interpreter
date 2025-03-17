#pragma once
#include "lexer.h"
#include "ast.h"

class Parser {
public:
    explicit Parser(Lexer& lexer);
    ASTNode* parse();

private:
    Lexer& lexer_;
    Token currentToken_;

    void eat(TokenType type);

    ASTNode* expr();   // addition and subtraction
    ASTNode* term();   // multiplication and division
    ASTNode* factor(); // numbers and parentheses
};
