#include "../include/lexer.h"
#include <cassert>
#include <iostream>

void testLexerSimpleExpression() {
    Lexer lexer("3 + 5");

    Token token1 = lexer.getNextToken();
    assert(token1.type == TokenType::Number && token1.value == 3);

    Token token2 = lexer.getNextToken();
    assert(token2.type == TokenType::Plus);

    Token token3 = lexer.getNextToken();
    assert(token3.type == TokenType::Number && token3.value == 5);

    Token token4 = lexer.getNextToken();
    assert(token4.type == TokenType::EndOfFile);
}

void testLexerParensAndOperators() {
    Lexer lexer("(7.5 - 2) * 4");

    assert(lexer.getNextToken().type == TokenType::LParen);
    assert(lexer.getNextToken().type == TokenType::Number);
    assert(lexer.getNextToken().type == TokenType::Minus);
    assert(lexer.getNextToken().type == TokenType::Number);
    assert(lexer.getNextToken().type == TokenType::RParen);
    assert(lexer.getNextToken().type == TokenType::Multiply);
    assert(lexer.getNextToken().type == TokenType::Number);
}

int main() {
    std::cout << "Running Lexer Tests...\n";

    testLexerSimpleExpression();
    testLexerParensAndOperators();

    std::cout << "All Lexer Tests Passed!\n";
    return 0;
}
