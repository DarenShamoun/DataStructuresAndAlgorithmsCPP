# Bag class functions

The goal of this lab is to continue creating a user defined
class template that encapsulates data storage that can grow
and shrink dynamically.

In this lab we will actually implement the functions 
that allow a bag to change size dynamically.

## Steps

### 1. Copy bag files
Copy your `bag.h` from the previous lab,
or my solution into the `src` directory.

### 2. Function `reserve`
Implement a function that will add extra *capacity* to our bag storage.

```cpp
void reserve(size_t new_capacity);
```
Because our backing store is an array, we just can't make it bigger.
We need to copy the current bag data into a new array and assign 
it to the backing store.

**Note:**

- Do not allow the capacity to be set less than the current capacity
- Do not change the size of the bag
- Do not initialize any of the new memory.
  Why don't we need to do this?
- Do not leak any memory.

Check your memory use with `valgrind` by running:

```
ctest -T memcheck -R step2
```

or manually as:

```
valgrind --leak-check=full test/step2
```


in your build directory.

**NOTE:** this command does not work on Windows.

### 3. Function `resize`
Implement a function that will add extra *capacity* to our bag storage
**and** initialize any data past the current size.

```cpp
void resize(size_t new_capacity);
```

**Note:**

- Call reserve to do most of your work.
- Don't overwrite any data already in the bag -
  just initialize any new capacity.
- Lastly, set the size to the new capacity

Check your memory use with `valgrind` by running:

```
ctest -T memcheck -R step3
```

or manually as:

```
valgrind --leak-check=full test/step3
```

in your build directory.

### 4. Function `push_back`
Implement a function that will add one element to a bag.

```cpp
void push_back(T value);
```

The `push_back` function will need to check if there is space available
in the backing store for another element.

If there is no space left,
then use `reserve` to double the capacity of the bag.

Keep in mind that a default constructed bag has capacity == 0.

### 5. Function `pop_back`
Implement a function that will remove one element from a bag.

```cpp
void pop_back();
```

### 6. Function `main`
Write a simple main function that uses your bag class.

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
[rate this lab](https://forms.gle/LTuBuDRmG9v1kURs7).
