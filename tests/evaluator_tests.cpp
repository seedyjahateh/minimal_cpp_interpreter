#include "../include/parser.h"
#include "../include/lexer.h"
#include "../include/evaluator.h"
#include <cassert>
#include <iostream>

void testSimpleEvaluation() {
    Lexer lexer("1 + 2");
    Parser parser(lexer);
    ASTNode* root = parser.parse();

    Evaluator evaluator;
    double result = evaluator.evaluate(root);
    assert(result == 3);

    delete root;
}

void testComplexExpressionEvaluation() {
    Lexer lexer("(2 + 3) * 4 - 10 / 2");
    Parser parser(lexer);
    ASTNode* root = parser.parse();

    Evaluator evaluator;
    double result = evaluator.evaluate(root);
    assert(result == 15);  // (2+3)=5 -> 5*4=20 -> 20-5=15

    delete root;
}

void testDivisionByZero() {
    Lexer lexer("10 / (5 - 5)");
    Parser parser(lexer);
    ASTNode* root = parser.parse();

    Evaluator evaluator;
    try {
        evaluator.evaluate(root);
        assert(false); // Should not reach here!
    } catch (const std::runtime_error& e) {
        assert(std::string(e.what()) == "Division by zero");
    }

    delete root;
}

int main() {
    std::cout << "Running Evaluator Tests...\n";

    testSimpleEvaluation();
    testComplexExpressionEvaluation();
    testDivisionByZero();

    std::cout << "All Evaluator Tests Passed!\n";
    return 0;
}
