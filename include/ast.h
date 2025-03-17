#pragma once
#include "lexer.h"

enum class ASTNodeType {
    Number,
    BinaryOp
};

struct ASTNode {
    ASTNodeType type;
    double value; // for Number node
    TokenType op; // for BinaryOp node
    ASTNode* left;
    ASTNode* right;

    ASTNode(double val); // number constructor
    ASTNode(TokenType op, ASTNode* left, ASTNode* right); // binary op constructor

    ~ASTNode(); // destructor to free children
};
