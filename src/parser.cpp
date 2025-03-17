#include "../include/parser.h"
#include "../include/lexer.h"
#include <stdexcept>



Parser::Parser(Lexer& lexer)
    : lexer_(lexer), currentToken_(lexer_.getNextToken()) {}

void Parser::eat(TokenType type) {
    if (currentToken_.type == type) {
        currentToken_ = lexer_.getNextToken();
    } else {
        throw std::runtime_error("Unexpected token");
    }
}

ASTNode* Parser::factor() {
    Token token = currentToken_;
    if (token.type == TokenType::Number) {
        eat(TokenType::Number);
        return new ASTNode(token.value);
    } else if (token.type == TokenType::LParen) {
        eat(TokenType::LParen);
        ASTNode* node = expr();
        eat(TokenType::RParen);
        return node;
    }

    throw std::runtime_error("Invalid factor");
}

ASTNode* Parser::term() {
    ASTNode* node = factor();

    while (currentToken_.type == TokenType::Multiply ||
           currentToken_.type == TokenType::Divide) {
        Token token = currentToken_;
        if (token.type == TokenType::Multiply) {
            eat(TokenType::Multiply);
        } else if (token.type == TokenType::Divide) {
            eat(TokenType::Divide);
        }

        node = new ASTNode(token.type, node, factor());
    }

    return node;
}

ASTNode* Parser::expr() {
    ASTNode* node = term();

    while (currentToken_.type == TokenType::Plus ||
           currentToken_.type == TokenType::Minus) {
        Token token = currentToken_;
        if (token.type == TokenType::Plus) {
            eat(TokenType::Plus);
        } else if (token.type == TokenType::Minus) {
            eat(TokenType::Minus);
        }

        node = new ASTNode(token.type, node, term());
    }

    return node;
}

ASTNode* Parser::parse() {
    return expr();
}
