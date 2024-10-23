## concepts of `typename` and `value_type` in C++ templates.

```cpp
// Example 1: Basic use of typename in templates
template <typename T>
class MyContainer {
public:
    T data;
};

// Example 2: typename for dependent types
template <typename Container>
void printFirstElement(const Container& c) {
    typename Container::value_type first = *(c.begin());
    std::cout << "First element: " << first << std::endl;
}

// Example 3: value_type in standard containers
#include <vector>
#include <string>

int main() {
    std::vector<int> intVector = {1, 2, 3};
    std::vector<int>::value_type intValue = intVector[0];  // intValue is an int

    std::vector<std::string> stringVector = {"hello", "world"};
    std::vector<std::string>::value_type stringValue = stringVector[0];  // stringValue is a std::string

    return 0;
}

// Example 4: Custom container with value_type
template <typename T>
class MyCustomContainer {
public:
    typedef T value_type;  // Defining value_type for our custom container

    // ... other members and methods
};

// Using the custom container
template <typename Container>
void useValueType(const Container& c) {
    typename Container::value_type value;
    // ... do something with value
}

```

Now, let's break down the concepts and examples:

1. `typename`:
   - `typename` is used in template declarations to specify that a dependent name is a type.
   - It's used in two main contexts:
     a. As an alternative to `class` in template parameter lists (Example 1).
     b. To clarify that a dependent name is a type (Example 2).

2. `value_type`:
   - `value_type` is not a keyword, but a convention used in C++ standard library containers.
   - It's typically a typedef or using declaration that represents the type of elements stored in a container.

Let's examine each example:

Example 1: Basic use of typename
- Here, `typename T` could also be written as `class T`. They're interchangeable in this context.
- This defines a template class that can hold any type T.

Example 2: typename for dependent types
- `typename Container::value_type` tells the compiler that `value_type` is a type dependent on `Container`.
- Without `typename`, the compiler might not recognize `value_type` as a type, leading to compilation errors.

Example 3: value_type in standard containers
- This shows how `value_type` is used with standard containers like `std::vector`.
- `std::vector<int>::value_type` is `int`.
- `std::vector<std::string>::value_type` is `std::string`.

Example 4: Custom container with value_type
- This demonstrates how to define `value_type` in your own container classes.
- The `useValueType` function shows how other code can use your container's `value_type`.

Key points to remember:
1. Use `typename` when referring to dependent types in templates.
2. `value_type` is a convention for the type of elements in a container.
3. Implementing `value_type` in your own containers can make them more compatible with generic algorithms.


## Difference between "new T[size]()" and "new T[size]"

The difference between `new T[size]()` and `new T[size]` is subtle but important, especially when dealing with primitive types and objects. Let's break it down:

1. `new T[size]`:
   - This allocates an array of `size` elements of type `T`.
   - For non-class types (like int, float, etc.), the elements are left uninitialized. Their values are indeterminate.
   - For class types, the default constructor is called for each element.

2. `new T[size]()`:
   - This also allocates an array of `size` elements of type `T`.
   - For non-class types, this performs zero-initialization. For example, all elements will be set to 0 for numeric types.
   - For class types, this behaves the same as `new T[size]` - the default constructor is called for each element.



```cpp
#include <iostream>

class MyClass {
public:
    int value;
    MyClass() : value(42) {
        std::cout << "MyClass default constructor called" << std::endl;
    }
};

int main() {
    const int size = 5;

    // Example with int (non-class type)
    int* arr1 = new int[size];  // Uninitialized
    int* arr2 = new int[size]();  // Zero-initialized

    std::cout << "arr1 (uninitialized):" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << arr1[i] << " ";  // Undefined behavior: values are indeterminate
    }
    std::cout << std::endl;

    std::cout << "arr2 (zero-initialized):" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cout << arr2[i] << " ";  // Will print 0 0 0 0 0
    }
    std::cout << std::endl;

    // Example with MyClass (class type)
    MyClass* obj1 = new MyClass[size];  // Calls default constructor for each element
    MyClass* obj2 = new MyClass[size]();  // Also calls default constructor for each element

    std::cout << "obj1[0].value: " << obj1[0].value << std::endl;  // Will print 42
    std::cout << "obj2[0].value: " << obj2[0].value << std::endl;  // Will also print 42

    // Clean up
    delete[] arr1;
    delete[] arr2;
    delete[] obj1;
    delete[] obj2;

    return 0;
}

```

Key points to remember:

1. For primitive types (like int, float, char, etc.):
   - `new T[size]` leaves the array uninitialized. Using the values without initializing them first is undefined behavior.
   - `new T[size]()` zero-initializes all elements.

2. For class types:
   - Both `new T[size]` and `new T[size]()` call the default constructor for each element.
   - The difference becomes apparent only if the class has a default constructor that does something other than zero-initialization.

3. In modern C++, consider using `std::vector` or `std::array` instead of raw arrays when possible. These container classes manage memory automatically and provide safer, more convenient interfaces.

4. When using `new[]`, always remember to use `delete[]` to properly deallocate the memory and call destructors for all elements.

5. In C++11 and later, you can also use uniform initialization syntax: `new T[size]{}`, which has the same effect as `new T[size]()`.

This distinction is particularly important when working with primitive types in performance-critical code, where unnecessary initialization can impact performance. For your `Array` class template, using `new T[this->_arr_size]()` ensures that all elements are properly initialized, which is generally a safe approach.


## Advance template: define custom memory allocation in a container

I'll explain how allocators and `rebind` work in C++98:

1. First, let's understand what allocators are:
```cpp
// When you declare a container like this:
std::vector<int> vec;

// It's actually equivalent to:
std::vector<int, std::allocator<int> > vec;
```

Allocators are classes that handle memory allocation and deallocation for containers. The second template parameter of standard containers is always an allocator.

2. The `rebind` is needed when an allocator for one type needs to allocate memory for a different type. Here's a simplified view:

```cpp
// This allocator can only allocate memory for ints
std::allocator<int>

// But in our sort, we need to allocate pairs of ints
// So we need: std::allocator<std::pair<int, int>>

// rebind helps us transform the first allocator into the second
typename Alloc::template rebind<std::pair<T, T> >::other
```

Let's break down this syntax:
```cpp
template < template <typename, typename> class Container, typename T, typename Alloc >
void merge_insertion_sort(Container<T, Alloc> &cont, ...) {
    // Original container uses Alloc to allocate T
    Container<T, Alloc> leftover;  // This is fine, same types as input

    // But for pairs container, we need an allocator for std::pair<T,T>
    // This is how we convert Alloc<T> to Alloc<std::pair<T,T>>:
    typedef typename Alloc::template rebind<std::pair<T, T> >::other PairAlloc;
    Container<std::pair<T, T>, PairAlloc> pairs;
}
```

Here's a concrete example:
```cpp
// Let's say you call the function with a deque of ints
std::deque<int> my_deque;  // implicitly uses std::allocator<int>

merge_insertion_sort(my_deque, my_deque.begin(), my_deque.end());

// Inside the function:
// Container = std::deque
// T = int
// Alloc = std::allocator<int>

// When creating leftover:
std::deque<int, std::allocator<int> > leftover;  // Same as input

// When creating pairs:
// Need: std::deque<std::pair<int,int>, std::allocator<std::pair<int,int> > >
// rebind helps transform std::allocator<int> into std::allocator<std::pair<int,int>>
typedef typename std::allocator<int>::template rebind<std::pair<int,int> >::other PairAlloc;
std::deque<std::pair<int,int>, PairAlloc> pairs;
```

3. Why is this necessary?
- Different types might have different memory requirements
- The allocator needs to know the size of the type it's allocating
- Without rebind, we'd need to manually specify new allocator types for each container

4. A simpler shorthand could be:
```cpp
// Instead of writing:
Container<std::pair<T, T>, typename Alloc::template rebind<std::pair<T, T> >::other> pairs;

// You could define a typedef:
typedef typename Alloc::template rebind<std::pair<T, T> >::other PairAlloc;
Container<std::pair<T, T>, PairAlloc> pairs;
```

This is essential in C++98 to maintain the same allocator family across different types while ensuring proper memory management. In modern C++ (C++11 and later), this has been simplified with features like `allocator_traits`, but in C++98, we need to use `rebind`.
