# Fixed array container

The goal of this lab is to create a user defined
class template that encapsulates a fixed array.

## Steps

### 1. Create files
Create files named `main.cpp` and `array.h`
in the `src` directory.

### 2. class template `array`
Create a data structure in the *mesa* `namespace`:

```cpp
// a value class for a fixed size array of type T
template<class T, size_t N>
  class array {
  };
```

Add a private member variable to store a stack allocated array
of type `T` and size `N`.
This array is called the *backing store*.
It is where our container (`mesa::array`) keeps its data.

add a public definition for the type `T`:

```cpp
using value_type = T
```

The `value_type` definition makes working with templates easier because
it makes it easier to determine the type of elements stored in the container.
Not the *values*, the *type*.

Since C++11, `auto` and `decltype` largely make the type interface
uneccessary, but it can simplify some statements and it is expected
for STL containers.
We will be discussing other type definitions in later labs.

Prior to C++11, we would use a public `typedef` to achieve the same goal:

```cpp
typedef T value_type
```

You will still see lots of code using the `typedef` form.

### 3. Function `size`
Implement a function size:

```cpp
constexpr size_t size()  const noexcept;
```

which will return the amount of space allocated for the array.

### 4. Functions `begin` and `end`
Implement functions `begin` and `end`:

```cpp
T* begin();
T* end();
```

`begin` should return a pointer to the first element of the array.

`end` should return a pointer *one position past* the last element
of the array.

Implement `constexpr` and non-const versions of these 2 functions.

### 5. Default constructor
Implement the default constructor.
Ensure when an array is constructed that each element
is initialized to the default value appropriate for its type:

- Numeric types should default to 0
- Other types should default to their defined default values
  as specified by their default constructors

### 6. Initializer list constructor
Implement a 1 argument constructor to create an array
from a list of values.
Use the following signature:

```cpp
explicit array(std::initializer_list<T>);
```

Copy each item from the provided list into the backing store.

**Hint:** `std::copy` will let you achieve this without resorting to
a hand-rolled loop.

### 7. Function `empty`
Implement a function empty:

```cpp
constexpr bool empty()  const noexcept;
```

which returns `true` if the array has no elements, `false` otherwise.

### 8. Function `main`
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
[rate this lab](https://forms.gle/qrt65tTrZwvnP6fc7).
