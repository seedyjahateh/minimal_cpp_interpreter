#include <iostream>
#include <string>
#include "lexer.h"
#include "parser.h"
#include "evaluator.h"

int main() {
    std::cout << "Minimal C++ Interpreter. Enter expressions or type 'exit':\n";

    std::string input;

    while (true) {
        std::cout << ">>> ";
        std::getline(std::cin, input);

        if (input == "exit" || input.empty()) {
            break;
        }

        try {
            Lexer lexer(input);
            Parser parser(lexer);
            ASTNode* tree = parser.parse();

            Evaluator evaluator;
            double result = evaluator.evaluate(tree);

            std::cout << "Result: " << result << "\n";

            delete tree; // free memory for AST

        } catch (const std::exception& ex) {
            std::cerr << "Error: " << ex.what() << "\n";
        }
    }

    std::cout << "Interpreter terminated.\n";
    return 0;
}
