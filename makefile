CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude

SRC = src/main.cpp src/lexer.cpp src/parser.cpp src/evaluator.cpp src/ast.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = interpreter

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(OBJ) $(TARGET)
lexer_tests:
	g++ -std=c++17 -Iinclude tests/lexer_tests.cpp src/lexer.cpp -o lexer_tests
	./lexer_tests

parser_tests:
	g++ -std=c++17 -Iinclude tests/parser_tests.cpp src/parser.cpp src/lexer.cpp src/ast.cpp -o parser_tests
	./parser_tests

evaluator_tests:
	g++ -std=c++17 -Iinclude tests/evaluator_tests.cpp src/parser.cpp src/lexer.cpp src/ast.cpp src/evaluator.cpp -o evaluator_tests
	./evaluator_tests
