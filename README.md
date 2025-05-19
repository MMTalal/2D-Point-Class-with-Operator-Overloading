# 2D Point Class with Operator Overloading

## Overview
This project implements a `Point` class in C++ that represents a point in 2D space (x, y coordinates). The class demonstrates various object-oriented programming concepts including:
- Constructors (default and parameterized)
- Getter and setter methods
- Operator overloading
- Member functions

## Features
The `Point` class supports the following operations:

### Basic Operations
- Default initialization to (0, 0)
- Custom initialization with x and y values
- Get and set individual coordinates
- Print current coordinates (`info()` method)

### Arithmetic Operations
- Element-wise multiplication of two points (`*` operator)
- Multiplication by a scalar (`*` operator)
- Element-wise subtraction of two points (`-=` operator)
- Subtraction of a scalar from both coordinates (`-=` operator)

### Comparison Operations
- Greater-than-or-equal comparison between two points (`>=` operator)

### Increment/Decrement Operations
- Pre-increment (`++Point`)
- Post-increment (`Point++`)
- Pre-decrement (`--Point`)
- Post-decrement (`Point--`)

## Code Example
```cpp
#include "Point.h"

int main() {
    Point P1(5, 3);
    Point P2(10, 9);
    
    // Multiplication
    Point P3 = P1 * P2;  // (50, 27)
    
    // Scalar operations
    Point P4 = P1 * 3;   // (15, 9)
    
    // Subtraction
    Point P5 = P1 -= P2; // (-5, -6)
    
    // Comparison
    bool isGreater = P1 >= P2;
    
    // Increment
    Point P6 = ++P1;     // (6, 4)
    
    return 0;
}
```

## How to Compile and Run
1. Save the code to a file (e.g., `Point.cpp`)
2. Compile using g++:
   ```bash
   g++ Point.cpp -o point_program
   ```
3. Run the executable:
   ```bash
   ./point_program
   ```

## Output
The program demonstrates all operations with clear output showing:
- Initial point coordinates
- Results of arithmetic operations
- Results of comparison operations
- Effects of increment/decrement operations

## Learning Objectives
This implementation demonstrates:
1. Class design in C++
2. Operator overloading
3. Object initialization
4. Const-correctness
5. Return value optimization

## License
This code is provided as-is for educational purposes. Feel free to use and modify it.
