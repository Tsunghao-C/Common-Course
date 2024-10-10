# C++ Literals and Type Identification

## What are Literals?

Literals are constant values that appear directly in code. They are fixed values that cannot be modified.

### Types of Literals

1. **Integer Literals**
```cpp
42      // decimal (int)
042     // octal (begins with 0)
0x2A    // hexadecimal (begins with 0x)
30u     // unsigned int
30l     // long
30ul    // unsigned long
```

2. **Floating-point Literals**
```cpp
3.14159     // double
3.14159f    // float
3.14159L    // long double
314159E-5   // double in scientific notation
```

3. **Character Literals**
```cpp
'A'         // char
L'A'        // wide character (wchar_t)
'\n'        // newline character
'\t'        // tab character
'\0'        // null character
```

4. **String Literals**
```cpp
"Hello"         // C-style string (const char*)
L"Hello"        // wide string (const wchar_t*)
```

5. **Boolean Literals**
```cpp
true    // boolean true
false   // boolean false
```

### Literal Suffixes

| Suffix | Meaning | Example |
|--------|----------|---------|
| u or U | unsigned | 42u |
| l or L | long | 42L |
| ul or UL | unsigned long | 42ul |
| f or F | float | 3.14f |
| l or L | long double | 3.14L |

## Identifying Data Types (C++98)

### 1. Using typeid Operator
```cpp
#include <typeinfo>
#include <iostream>

int main() {
    // Integer literals
    std::cout << "Type of 42: " << typeid(42).name() << std::endl;
    std::cout << "Type of 42L: " << typeid(42L).name() << std::endl;
    
    // Floating-point literals
    std::cout << "Type of 3.14: " << typeid(3.14).name() << std::endl;
    std::cout << "Type of 3.14f: " << typeid(3.14f).name() << std::endl;
}
```

### 2. Using Template Functions
```cpp
#include <iostream>

template<typename T>
void printType(T value) {
    if (typeid(value) == typeid(int))
        std::cout << "Integer type" << std::endl;
    else if (typeid(value) == typeid(float))
        std::cout << "Float type" << std::endl;
    else if (typeid(value) == typeid(double))
        std::cout << "Double type" << std::endl;
}

int main() {
    printType(42);      // Integer type
    printType(3.14f);   // Float type
    printType(3.14);    // Double type
    return 0;
}
```

### 3. Default Type Rules

1. **Integer Literals**:
   - Decimal: First type in which it fits: int, long, unsigned long
   - Octal/Hex: First type in which it fits: int, unsigned int, long, unsigned long

2. **Floating-point Literals**:
   - No suffix: double
   - f or F suffix: float
   - l or L suffix: long double

### Complete Example with Type Checking
```cpp
#include <iostream>
#include <typeinfo>
#include <string>

class TypeChecker {
public:
    static void checkType(const char* literal) {
        // Try integer conversion
        try {
            int i = std::atoi(literal);
            if (std::string(literal) == std::to_string(i)) {
                std::cout << literal << " is an integer" << std::endl;
                return;
            }
        } catch (...) {}

        // Try float conversion
        try {
            float f = std::atof(literal);
            if (literal[strlen(literal)-1] == 'f' || 
                literal[strlen(literal)-1] == 'F') {
                std::cout << literal << " is a float" << std::endl;
                return;
            }
        } catch (...) {}

        // Try double conversion
        try {
            double d = std::atof(literal);
            if (std::string(literal).find('.') != std::string::npos) {
                std::cout << literal << " is a double" << std::endl;
                return;
            }
        } catch (...) {}

        std::cout << literal << " type cannot be determined" << std::endl;
    }
};

int main() {
    TypeChecker::checkType("42");      // integer
    TypeChecker::checkType("3.14");    // double
    TypeChecker::checkType("3.14f");   // float
    TypeChecker::checkType("123.456"); // double
    return 0;
}
```

### Common Pitfalls to Avoid

1. **Implicit Type Conversion**
```cpp
float f = 3.14;    // Warning: implicit conversion from double to float
float f2 = 3.14f;  // Correct: explicit float literal
```

2. **Integer Overflow**
```cpp
int x = 2147483648;     // Overflow if int is 32-bit
long y = 2147483648L;   // Correct: long literal
```

3. **Precision Loss**
```cpp
float f = 3.14159265359;    // Precision loss
double d = 3.14159265359;   // Better precision
```

### Best Practices

1. Always use suffixes when specific types are required
2. Be explicit about your intentions with literal types
3. Use appropriate type for the data range you need
4. Consider readability when using numeric literals
5. Be careful with type conversions and potential precision loss