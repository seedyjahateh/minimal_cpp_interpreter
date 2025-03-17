#include "lexer.h"
#include <cctype>
#include <stdexcept>

Lexer::Lexer(const std::string& input)
    : input_(input), pos_(0) {
    currentChar_ = input_.empty() ? '\0' : input_[pos_];
}

void Lexer::advance() {
    pos_++;
    currentChar_ = (pos_ < input_.length()) ? input_[pos_] : '\0';
}

void Lexer::skipWhitespace() {
    while (std::isspace(currentChar_)) {
        advance();
    }
}

double Lexer::number() {
    std::string result;
    while (std::isdigit(currentChar_) || currentChar_ == '.') {
        result += currentChar_;
        advance();
    }
    return std::stod(result);
}

Token Lexer::getNextToken() {
    while (currentChar_ != '\0') {
        if (std::isspace(currentChar_)) {
            skipWhitespace();
            continue;
        }

        if (std::isdigit(currentChar_) || currentChar_ == '.') {
            return Token{ TokenType::Number, number() };
        }

        if (currentChar_ == '+') {
            advance();
            return Token{ TokenType::Plus, 0 };
        }

        if (currentChar_ == '-') {
            advance();
            return Token{ TokenType::Minus, 0 };
        }

        if (currentChar_ == '*') {
            advance();
            return Token{ TokenType::Multiply, 0 };
        }

        if (currentChar_ == '/') {
            advance();
            return Token{ TokenType::Divide, 0 };
        }

        if (currentChar_ == '(') {
            advance();
            return Token{ TokenType::LParen, 0 };
        }

        if (currentChar_ == ')') {
            advance();
            return Token{ TokenType::RParen, 0 };
        }

        throw std::runtime_error("Unknown character in input");
    }

    return Token{ TokenType::EndOfFile, 0 };
}
