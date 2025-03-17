#include "ast.h"

ASTNode::ASTNode(double val)
    : type(ASTNodeType::Number), value(val), left(nullptr), right(nullptr) {}

ASTNode::ASTNode(TokenType op, ASTNode* left, ASTNode* right)
    : type(ASTNodeType::BinaryOp), op(op), left(left), right(right) {}

ASTNode::~ASTNode() {
    delete left;
    delete right;
}
