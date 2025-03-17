#pragma once
#include <string>

enum class TokenType {
    Number,
    Plus,
    Minus,
    Multiply,
    Divide,
    LParen,
    RParen,
    EndOfFile
};

struct Token {
    TokenType type;
    double value; // only valid if type == Number
};

class Lexer {
public:
    explicit Lexer(const std::string& input);
    Token getNextToken();

private:
    std::string input_;
    size_t pos_;
    char currentChar_;

    void advance();
    void skipWhitespace();
    double number();
};
