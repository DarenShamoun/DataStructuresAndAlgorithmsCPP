# Linked list iterators
The goal of this lab is to finish the list started
in the previous lab.
While that work was a good start,
there are many things we expect from containers that our list
doesn't support yet:
- No support for a range-for loop
- No equivalence relations.
  We could have written them,
  but each would have needed their own private list traversal.
- Impossible to use with most STL algorithms

We need a basic iterator interface.

In the array and bag classes, we got our pointer increment functions
for 'free' - the array backing store is trivially incremented.

A linked list iterator is not automatic. 
A separate `iterator` class is used to provide an interface
that mimics pointer postfix and prefix increment.
The iterator also makes `begin()` and `end()` possible.

## Steps

### 1. Copy files
Copy your `list.h` from the previous lab or
copy my solution as you prefer.
If you created a `main`, you may copy that as well, if you plan to reuse it.

### 2. `list_iterator` types
Create a struct template `list_iterator`.

```cpp
template <typename T>
struct list_iterator {
};
```

In order to create an iterator that works with the STL,
a very specific set of type interfaces is required.
We have already been using one: `value_type`.
A minimum set to support iterator usage in this lab are:

```cpp
using value_type = T;
using pointer = T*;
using reference = T&;
using difference_type = std::ptrdiff_t;
using iterator_category = std::forward_iterator_tag;
```

The type `std::forward_iterator_tag` is defined in `<iterator>`.
The type `ptrdiff_t` is defined in `<cstddef>`.

Add a member variable to store a pointer to a `list_node`.
For testing purposes, name this variable `node`.

### 3. Iterator constructors and assignment overloads
Implement the following:

- Implement a constructor that takes a pointer to a `list_node`
  and stores it in the iterator.
- Implement the default constructor.

### 4. Iterator Dereference and increment
Implement an overload for the dereference operator that returns
the value stored in the `list_node`.

Implement overloads for **prefix** increment and **postfix** increment.

Recall that postfix increment uses a dummy (unused) parameter to distinguish the
two overloads, postfix and prefix increment.

Because prefix increment returns the `this` pointer,
it **must** be implemented as a `list_iterator` member function.

Implement overloads for `==` and `!=`.
Consider 2 iterators equivalent if they both point to the same `list_node`.

Equivalence overloads can be implemented as friends of the `list_iterator`
or not as you prefer, but they should alway be non-member functions.

### 5. Refactor list to use iterator
Add a public type alias for a `list_iterator` to your list.
A typedef or using declaration can be used here,
but using declarations are preferred.
This type should be named `iterator`.

Add `constexpr` and non-const versions of `begin` and `end` functions.

Make sure your functions return the `iterator` type
and implement them in the `list` class.

```cpp
iterator begin() noexcept;
iterator end() noexcept;
```

Refactor `insert_after`, replacing the integer positional parameter
and return value with an iterator.

```cpp
iterator insert_after(iterator it, const T& value);
```

The returned iterator should point to the newly inserted value.

### 6. Function `erase_after`
Implement a function that erases the list element **after** the provided
iterator position.

```cpp
iterator erase_after(iterator it);
```

The function should return the iterator position following the erased one.

### 7. Function `main`
Write a main function that uses each of your `mesa::list` functions at least once.
Add a range-for loop and use your iterator interface.
Consider `std::advance` or STL algorithms.


### Try This!
Add Move constructors and Move assignment to your bag.

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
[rate this lab](https://forms.gle/FJmEmxF6q5nR7k7w5).
