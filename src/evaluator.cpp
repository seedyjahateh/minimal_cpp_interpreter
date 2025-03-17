#include "evaluator.h"
#include <stdexcept>

double Evaluator::evaluate(ASTNode* node) {
    if (node->type == ASTNodeType::Number) {
        return node->value;
    }

    double leftVal = evaluate(node->left);
    double rightVal = evaluate(node->right);

    switch (node->op) {
        case TokenType::Plus:
            return leftVal + rightVal;
        case TokenType::Minus:
            return leftVal - rightVal;
        case TokenType::Multiply:
            return leftVal * rightVal;
        case TokenType::Divide:
            if (rightVal == 0) {
                throw std::runtime_error("Division by zero");
            }
            return leftVal / rightVal;
        default:
            throw std::runtime_error("Unknown binary operator");
    }
}
