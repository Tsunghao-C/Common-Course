# Module 01 - The use of pointer and reference

## What's the difference of creating member variable and member reference?

```
// Previous version
class Example1 {
    std::string data;
public:
    Example1(const std::string& s) : data(s) {}
    void modifyData() { data += " modified"; }
};

// New version with reference member
class Example2 {
    std::string& data;
public:
    Example2(std::string& s) : data(s) {}
    void modifyData() { data += " modified"; }
};

// Usage
std::string str = "Hello";
Example1 e1(str);
Example2 e2(str);

e1.modifyData(); // Only e1's internal data is modified
e2.modifyData(); // The original 'str' is modified

std::cout << "str after e1 modification: " << str << std::endl;
std::cout << "str after e2 modification: " << str << std::endl;
```


### Ownership and Lifetime:

Example1 owns its data. The data member is a separate copy of the string passed to the constructor.
Example2 doesn't own its data. The data member is a reference to the original string passed to the constructor.


### Lifetime Dependencies:

Example1 objects can safely outlive the original string they were constructed with.
Example2 objects must not outlive the original string they reference, or they'll end up with a dangling reference.


### Modifications:

Changes to data in Example1 only affect the internal copy.
Changes to data in Example2 directly affect the original string.


### Const-correctness:

Example1 can take a const std::string& in its constructor, allowing it to be constructed from temporary strings or const strings.
Example2 requires a non-const std::string&, limiting its usability with const or temporary strings.


### Memory Usage:

Example1 uses more memory as it stores its own copy of the string.
Example2 uses less memory as it only stores a reference.


### Thread Safety:

Example1 is inherently more thread-safe as it operates on its own internal data.
Example2 can lead to race conditions if the original string is accessed from multiple threads.


### Flexibility:

Example1 can be easily made to work with both lvalues and rvalues by adding a move constructor.
Example2 is limited to lvalue references and can't directly accept rvalues or temporary objects.


### Semantics:

Example1 follows value semantics, which is generally more intuitive and less error-prone.
Example2 follows reference semantics, which can be powerful but requires careful management.



The version with the reference member (Example2) can be useful in specific scenarios, such as:

When you want to create a view or wrapper around existing data without copying it.
When you need to modify the original data directly through the class interface.
In performance-critical situations where avoiding copies is crucial and you can guarantee proper lifetime management.

However, it comes with significant risks and limitations:

It's easy to create dangling references if not managed carefully.
It's less flexible in terms of what can be passed to the constructor.
It can lead to unexpected behavior if users of the class aren't aware that it modifies external data.

In general, the value-based approach (Example1) is safer and more commonly used. It provides better encapsulation, is less prone to errors, and is more flexible. The reference-based approach should be used judiciously and with clear documentation about its behavior and lifetime requirements.
