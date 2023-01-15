# Data Structures
Implement a simple linked data structure using `struct` 

The `struct` data structure is one that C++ inherits from C.
In C, a struct may contain data types only.
In C++, a `struct` that contains only data is called a *POD* -
Plain Old Data.

C++ extends the capabilities of a C `struct`.
Today we will start exploring that in C++11,
a `struct` can contain both data, constructors, and functions.

An important part of this lab is implementing your functions in the cpp file.

## Steps
Implement the following:

### 1. Create files
Create the files `list.h` and `list.cpp`.

Create the file `main.cpp`, 
even though implementing `main` is an optional step.

### 2. struct `list`
Define a struct `list` in file `list.h`.

```cpp
struct list {
  int value = 0;
  list* next = nullptr;
};
```

**Note:** this struct does **not** reside in namespace mesa.

Also notice the default assignment of the struct members.
This is a C++11 feature.


### 3. list constructor
Add a list constructor that converts an `int` into a `list`:

```cpp
explicit list(const int value = 0);
```

The `explicit` is used to prevent implicitly creating a list,
when you did not intend to.

The default value assignment allows a default constructed list:

```
list foo;
```

### 4. Function `insert`
Create a function with the following signature:

```cpp
list* insert(int);
```

Take the int provided and insert a new list node before the current element.

Return a pointer to the new element created by the function.

### 5. Function `operator<<`
Create an ostream overload that will print the contents of a list:

```cpp
std::ostream& operator<<(std::ostream&, const list*);

```

Notes:

- This function must **not** be a `list` member function.
- Separate each list member with a single space
- The tests expect a traling space at the end of the list


### 6. Function `erase`
Create a non-member function with the following signature:

```cpp
list* erase(list*);
```

That removes the provided element from the list without invalidating
all the remaining list pointers.

Return a pointer to the list element after the deleted one.

## Try this!
Consider writing a main that uses your list struct.

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
[rate this lab](https://forms.gle/vkWBTpyznuT6grgb6).
