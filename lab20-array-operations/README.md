# `mesa::array` operations

The goal of this lab is to create a user defined
class template that encapsulates a fixed array.

It builds on the previous lab to add comparison operations,
array index access, and range checked access.

## Steps

### 1. Copy files
Copy your source files from the previous lab,
or my solution into the `src` directory.

### 2. Function `operator[]`
Implement a function to access elements from the array using an index:

```cpp
constexpr const T& operator[](size_t index) const;
```

Implement both the `const` version (above) and a non-const version.

### 3. Function `at`
Implement a function to access elements from the array using an index:

```cpp
constexpr const T& at(size_t index) const;
```

However, for this version of the function,
throw a `std::out_of_range` exception if an invalid array index is provided. 

Implement both the `const` version (above) and a non-const version.

### 4. Functions `data` and `back`
Implement a function `data` to access a pointer to the underlying backing store.

```cpp
T* data();
```
Implement a function `back` to access a reference to the last element
of the backing store.

```cpp
T& back();
```
Implement `constexpr` versions of both functions.

### 5. Function `operator==` overload
Implement a non-member function overload to check if 2 arrays are equal:

```cpp
bool operator==(const mesa::array<T,N>&, const mesa::array<T,N>&);
```

**Hint:** Use `std::equal`.

When `operator==` is complete, implement `operator!=`.

### 6. Function `operator<` overload
Implement a non-member function overload to check if one array is less than
a second array.

```cpp
bool operator<(const mesa::array<T,N>&, const mesa::array<T,N>&);
```

**Hint:** Use `std::lexicographical_compare`.

When `operator<` is complete, implement the remaining relational operations.


### 7. Function `main`
Write a main function that uses each of your `mesa::array` functions at least once.

## Turnitin
Check your progress by running `make test` or `ctest -V`.
This will attempt to run all tests.
Check partial progress by running the tests for a single step.
You can run tests for a single step with an IDE or ctest,
for example, `ctest -R step2`.

- Add your new and modified files: `git add . . . `
- Save your changes: `git commit . . . `
- Submit your work for grading: `git push`

## Reflection
When you are done, take a moment to 
[rate this lab](https://forms.gle/7s5N9fWcpJHkpLwa7).
