# Minimal C++ Interpreter for Arithmetic Expressions

An attempt to build a minimal C++ interpreter specifically designed to parse and evaluate arithmetic expressions.

## 📚 Project Overview
This project is a **minimal C++ interpreter** that parses and evaluates arithmetic expressions, following **C++ operator precedence** and **associativity rules**. It acts as a simple calculator, showcasing fundamental concepts of **interpreters**, **parsers**, and **evaluators**.

The interpreter consists of three main components:
- **Lexer (Tokenizer)**: Breaks input into tokens
- **Parser (Syntax Analyzer)**: Builds an Abstract Syntax Tree (AST)
- **Evaluator**: Computes the final result from the AST

---

## 🎯 Project Objectives (Scope Statement)
- Implement an interpreter that handles **basic arithmetic operations**:
  - Addition (`+`)
  - Subtraction (`-`)
  - Multiplication (`*`)
  - Division (`/`)
- Support **parentheses** for altering operation precedence.
- Follow **C++ precedence and associativity rules**.
- Keep the design **modular**, **clean**, and **extensible**.

> **Out of Scope**:
> - Variable assignment and storage
> - Functions or advanced data types
> - Error recovery (only basic exception handling)

> ⚠️ **Project Scope Management** (Lee Evans PM Notes):  
> Defining clear in-scope vs. out-of-scope items avoids scope creep and ensures a focused, manageable deliverable.

---

## ✨ Features
✅ Arithmetic parsing and evaluation  
✅ C++-style precedence and associativity  
✅ Recursive descent parser  
✅ Unit tests for Lexer, Parser, and Evaluator  
✅ Clean, modular C++ code  
✅ Error handling for invalid input and division by zero  

---

<!-- ## 🗂️ Project Structure

minimal_cpp_interpreter/
    ├── include/
        ├── lexer.h
        ├── parser.h
        ├── ast.h
        ├── evaluator.h 
    ├── src/
        ├── lexer.cpp
        ├── parser.cpp
        ├── ast.cpp
        ├── evaluator.cpp
        ├── main.cpp 
    ├── tests/
        ├── lexer_tests.cpp
        ├── parser_tests.cpp
        ├── evaluator_tests.cpp 
    ├── README.md
    ├── Makefile (optional) -->

## 🏗️ Project Management Insights (Inspired by Lee Evans' Project Management Study Notes)

### 1. Scope Management
- **Defined Deliverables**: Deliver a minimal interpreter for arithmetic expressions.
- **Scope Creep Prevention**: Features like variables, functions, and advanced error recovery are intentionally excluded from this version.
- **Scope Statement**: The interpreter will evaluate basic arithmetic expressions with C++ precedence rules, avoiding unnecessary complexity.

---

### 2. Schedule and Time Management
#### Work Breakdown Structure (WBS):
- **Task 1**: Implement Lexer (2 days)
- **Task 2**: Implement Parser (2-3 days)
- **Task 3**: Implement Evaluator (1-2 days)
- **Task 4**: Write Unit Tests (2 days)
- **Task 5**: Final Testing and Documentation (1 day)

#### Milestones:
- ✅ Lexer Completed  
- ✅ Parser Completed  
- ✅ Evaluator Completed  
- ✅ Unit Testing  
- ✅ Documentation  

---

### 3. Risk Management

| **Identified Risks**                    | **Mitigation Strategy**                                 |
|----------------------------------------|---------------------------------------------------------|
| Misunderstanding operator precedence   | Cross-reference with C++ operator precedence tables     |
| Memory leaks due to manual memory mgmt | Plan for smart pointer refactoring in future versions   |
| Tight deadlines                        | Prioritize critical features; defer non-essential ones  |

> Lee Evans emphasizes **risk identification and mitigation planning** to ensure smooth project delivery.

---

### 4. Quality Management
- **Quality Planning**: Write clean, modular, and maintainable code from the outset.
- **Quality Assurance**: Unit testing for Lexer, Parser, and Evaluator components.
- **Quality Control**: Continuous validation against expected outputs, automated test runs.
- **Code Reviews (Optional)**: Perform peer reviews or self-reviews on each module.

---

### 5. Communications Management
- Document progress in this `README.md`.
- Maintain a clear list of deliverables and scope in case of stakeholder communication.
- Plan periodic check-ins with any involved stakeholders (advisors, instructors).

> Lee Evans highlights the importance of **clear and timely communications** for project success.

---

### 6. Integration Management
- Integrate components (Lexer → Parser → Evaluator) incrementally and validate after each phase.
- Maintain modular design to reduce integration complexity.
- Ensure proper hand-off between components via clearly defined interfaces.

---

## 📈 Future Enhancements

| **Feature**               | **Priority** | **Description**                                      |
|---------------------------|--------------|------------------------------------------------------|
| Support for variables      | Medium       | Add symbol tables and variable assignments          |
| Functions and procedures   | Low          | Support for custom function definitions and calls   |
| Unary operators (+, -)     | Medium       | Handle expressions like `-5 + 2`                    |
| Smart pointer refactoring  | High         | Replace raw pointers with `std::unique_ptr`         |
| Scripting support (REPL)   | Low          | Multi-line input with state retention               |
| Better error recovery      | Medium       | Improve diagnostics and user feedback on errors     |

---

## 🛠️ Tools & Technologies
- **C++17**
- **g++**
- **Optional**:
  - Git Bash / MinGW / WSL (for Unix-like development on Windows)
  - GoogleTest or Catch2 for future advanced testing frameworks

---

## 📜 License
**MIT License**  
Feel free to use, modify, and distribute this project under the terms of the MIT license.


## 🔨 Build and Run Instructions

### ⚙️ Prerequisites
- `g++` compiler (C++17 or newer)
- (Optional) Git Bash or MinGW for a Unix-like terminal on Windows

### ⚙️ Compile and Run
```bash
# Compile the interpreter
g++ -std=c++17 -Iinclude src/*.cpp -o interpreter.exe

# Run the interpreter
./interpreter.exe


# ---------- TESTS -----------

# Lexer Tests
g++ -std=c++17 -Iinclude tests/lexer_tests.cpp src/lexer.cpp -o lexer_tests.exe
./lexer_tests.exe

# Parser Tests
g++ -std=c++17 -Iinclude tests/parser_tests.cpp src/parser.cpp src/lexer.cpp src/ast.cpp -o parser_tests.exe
./parser_tests.exe

# Evaluator Tests
g++ -std=c++17 -Iinclude tests/evaluator_tests.cpp src/parser.cpp src/lexer.cpp src/ast.cpp src/evaluator.cpp -o evaluator_tests.exe
./evaluator_tests.exe

