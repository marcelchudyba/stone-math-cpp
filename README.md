# StoneMath

StoneMath is a fast, safe, and easy-to-use mathematical expression parser and evaluator written in C++. The engine utilizes the classic Shunting-yard algorithm for lexical analysis (Lexer), parsing (Parser), and evaluating (Evaluator) complex mathematical equations.

## ⚙️ Requirements

To build the project, you will need:
*   A compiler with **C++20** support.
*   **CMake** version **3.29** or higher.

## 🚀 Key Features

*   **Basic Arithmetic:** Addition `+`, subtraction `-`, multiplication `*`, division `/`.
*   **Order of Operations & Parentheses:** Full support for nested parentheses `()` and operator precedence.
*   **Exponentiation:** Support for the `^` operator with **right-associativity** (e.g., `2^3^2` is evaluated as `2^(3^2)`).
*   **Negative Numbers:** Built-in, seamless handling of the unary minus (e.g., `-5 + 3`, `10 * (-2)`).
*   **Math Functions:** Support for basic functions: `sin()`, `cos()`, `tan()`, `sqrt()`.
*   **Error Handling:** Strict data validation. The parser throws clear exceptions for syntax errors, division by zero, empty functions, or attempting to calculate the square root of a negative number (NaN).

## 📁 Project Structure

The project is divided into clean, modular layers:
*   `include/` - Header files (`Lexer.h`, `Parser.h`, `Evaluator.h`, `StoneMath.h`, `TokenType.h`).
*   `src/` - Core logic implementation.
*   `tests/` - A suite of unit and integration tests verifying algorithm correctness.

## 🛠 Installation & Building

The project is configured using CMake to build the main engine as a **static library** (`StoneMath`) and a separate executable for tests (`StoneMath_Tests`).

To compile everything, run the following commands in your terminal:
```bash
# 1. Clone the repository
git clone [https://github.com/marcelchudyba/stone-math-cpp.git]
cd StoneMath

# 2. Create a build directory
mkdir build
cd build

# 3. Generate files and build the project
cmake ..
cmake --build .
```

## 💻 Usage Example (C++)

The main interface of the library is the `StoneMath` class. Initialization and result evaluation take just two lines of code:
```cpp
#include <iostream>
#include <string>
#include "StoneMath.h"

int main() {
    std::string equation = "100 / (10 + 15 * (sqrt(4) - 2))";

    try {
        // 1. Initialize the engine with an expression
        StoneMath::StoneMath engine = StoneMath::StoneMath(equation);
        
        // 2. Evaluate the result (the Evaluator argument can be used for variables in the future)
        double result = engine.Evaluate(0);
        
        std::cout << "Equation: " << equation << "\n";
        std::cout << "Result: " << result << "\n"; // Expected result: 10.0
    }
    catch (const std::exception& e) {
        // Catch parsing and evaluation errors
        std::cerr << "[ERROR] " << e.what() << "\n";
    }

    return 0;
}
```

## 🧪 Tests

The project includes a dedicated executable for testing. After building the project (following the instructions above), you can run a rigorous suite of unit and integration tests by typing the following in the `build` directory:
```bash
# On Linux / macOS:
./StoneMath_Tests

# On Windows:
Debug\StoneMath_Tests.exe
```

The tests verify:
*   Left and right associativity.
*   Proper handling of stack nesting and parentheses.
*   Ignoring whitespaces.
*   Complex nesting scenarios (Stress Tests).
*   Intentionally triggering exceptions to check the robustness of the parser and evaluator.

## 📄 License

This project is licensed under the MIT License - see the `LICENSE` file for details.