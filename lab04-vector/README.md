# Using std::vector

## Overview
The purpose of this exercise is to practice working with `std::vector`
and traditional loops.

We will be writing functions that take a `const char* []` parameter,
fill a vector from the array data,
and perform a computation on the vector elements. 

Do not hesitate to review the vector API at
[cppreference.com](https://en.cppreference.com/w/cpp/container/vector)

I recommend you always look here first if you have a question
about a C++ construct.

**Remember**

Keep your functions simple.

There is no need to worry about leading or trailing spaces
for any of these functions.

## Steps

### 1. Create files
Create files named `lab4.cpp` and `lab4.h`
in the `src` directory.

Your function declarations will reside in the `.h` file.

Your function implementations will reside in the `.cpp` file.

### 2. Function make_vector
Create a function with the following signature:
   
```cpp
std::vector<int> make_vector(int argc, const char* argv[]);
```

Implement `make_vector`.
Take each array element, one at a time, from `argv`,
convert the character data to an integer,
and `push_back` the result onto a vector.

If the array has no elements, then return an empty vector.

### 3. Function add
Create a function with the following signature:
   
```cpp
int add(int argc, const char* argv[]);
```

Implement `add`.
Use `make_vector` to initialize a new vector.
Compute the sum of all the values in the vector
and return the result.

Do not use any standard library functions to compute the sum.

If the array provided has no elements, then return 0.

### 4. Function mean
Create a function with the following signature:
   
```cpp
double mean(int argc, const char* argv[]);
```

Compute the average of all the values in the vector
and return the result.

Consider calling `add` as part of your `mean` implementation.

Do not use any standard library functions to compute the mean.

If the array provided has no elements, then return 0.

### 5. Function odd
Create a function with the following signature:
   
```cpp
std::vector<int> odd(std::vector<int>);
```

Implement `odd`.
Return only the odd integers copied from the vector provided.

If the vector has no elements, then return an empty vector.

### 6. Function reverse
Create a function with the following signature:
   
```cpp
std::vector<int> reverse(std::vector<int>);
```

Implement `reverse`.
Return all the integers provided, but in reverse order.

If the vector has no elements, then return an empty vector.

Do not use any standard library functions to reverse the data.

## Turnitin
Check your progress by running `make test` or `ctest -V`.
This will attempt to run all tests.
Check partial progress by running the tests for a single step.
You can run tests for a single step with an IDE or ctest,
for example, `ctest -R step2`.

- Add your new and modified files: `git add src`
- Save your changes: `git commit -m 'finish lab4'`
- Submit your work for grading: `git push`

## Reflection
When you are done, take a moment to [rate this lab](https://forms.gle/u233d5qXTPPdZiag6).

