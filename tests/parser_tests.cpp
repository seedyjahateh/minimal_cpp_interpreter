#include "../include/parser.h"
#include "../include/lexer.h"
#include "../include/ast.h"
#include <cassert>
#include <iostream>

void testSimpleAdditionAST() {
    Lexer lexer("2 + 3");
    Parser parser(lexer);

    ASTNode* root = parser.parse();
    assert(root != nullptr);
    assert(root->type == ASTNodeType::BinaryOp);
    assert(root->op == TokenType::Plus);
    assert(root->left->type == ASTNodeType::Number && root->left->value == 2);
    assert(root->right->type == ASTNodeType::Number && root->right->value == 3);

    delete root;
}

void testPrecedenceAST() {
    Lexer lexer("2 + 3 * 4");
    Parser parser(lexer);

    ASTNode* root = parser.parse();
    assert(root != nullptr);
    assert(root->type == ASTNodeType::BinaryOp);
    assert(root->op == TokenType::Plus);

    assert(root->left->type == ASTNodeType::Number && root->left->value == 2);

    ASTNode* right = root->right;
    assert(right->type == ASTNodeType::BinaryOp);
    assert(right->op == TokenType::Multiply);
    assert(right->left->value == 3);
    assert(right->right->value == 4);

    delete root;
}

int main() {
    std::cout << "Running Parser Tests...\n";

    testSimpleAdditionAST();
    testPrecedenceAST();

    std::cout << "All Parser Tests Passed!\n";
    return 0;
}
