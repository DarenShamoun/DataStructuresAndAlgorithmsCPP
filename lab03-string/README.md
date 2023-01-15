# Using std::string

## Overview
The purpose of this exercise is to practice working with `std::string`.

We will be writing functions that take a string parameter and either
modify it in some way, or return it untouched.

One goal of this lab is to minimize using loops.
In most places where looping over characters one at a time could be done,
the `std::string` class provides a function that replaces the loop.

In your first semester, 
you learned how to write basic conditional and looping statements.
While these basic constructs are important,
most of this course focuses on
using data structures to avoid writing raw loops.

Do not hesitate to review the string API at
[cppreference.com](https://en.cppreference.com/w/cpp/string/basic_string)

I recommend you always look here first if you have a question
about a C++ construct.

**Remember**

Keep your functions simple.

There is no need to worry about leading or trailing spaces
for any of these functions.

## Steps

### 1. Create files
Create files named `lab3.cpp` and `lab3.h`
in the `src` directory.

Your function declarations will reside in the `.h` file.

Your function implementations will reside in the `.cpp` file.

### 2. Function `sentence_case`
Create a function with the following signature:
   
```cpp
std::string sentence_case(std::string);
```

Implement `sentence_case` so that if the last character is a period (.),
then the first letter is changed to upper case.

If the last character is **not** a period, then return the string unchanged.

### 3. Function `phone_format`
Create a function with the following signature:
   
```cpp
std::string phone_format(std::string);
```

Implement `phone_format` so that
if the string is exactly 10 characters and all are digits,
then assume it is a phone number.
Transform into a formatted string:

```
(ddd) ddd-dddd
```

If the string fails the phone number test, then return the string:

```
Not a phone number.
```

### 4. Function `name_format`
Create a function with the following signature:

```
std::string name_format(std::string);
```

Implement `name_format` so that
if the string is exactly 2 words separated by a space,
then assume it is a name, `firstname lastname`.
Transform the string to:

```
Lastname, F.
```

where **F** is the first letter of the first name and return it.

## Turnitin
Check your progress by running `make test` or `ctest -V`.
This will attempt to run all tests.
Check partial progress by running the tests for a single step.
You can run tests for a single step with an IDE or ctest,
for example, `ctest -R step2`.

- Add your new and modified files: `git add src README.md`
- Save your changes: `git commit -m 'finish lab3'`
- Submit your work for grading: `git push`

## Reflection
When you are done, take a moment to [rate this lab](https://forms.gle/RUtdjCc4RMKxcAZE7).

