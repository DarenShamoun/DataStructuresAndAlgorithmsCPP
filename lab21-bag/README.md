# Bag class

The goal of this lab is to create a user defined
class template that encapulates data storage that can grow
and shrink dynamically.

This data type is sometimes referred to as a `bag`:
a general expandable storage container with things thrown in
no particular order.

Like an array, a bag can access elements by index and
iterate through all the elements in the container one at a time.

Unlike an array, a bag can expand its storage as needed.
Because the bag stores all of it's data on the free store,
the amount of data it can hold is limited only by available system memory.

## Steps

### 1. Copy array files
Copy your `array.h` and `main.cpp` from the previous lab,
or my solution into the `src` directory.

### 2. Refactor `mesa::array`
Use either your IDE refactoring tools, or you can make the changes manually:

- Rename `array.h` to `bag.h`
- Edit bag.h and change all the strings `array` to `bag`
- Remove all references to the non-type template parameter N
- Change the backing store to be type `T*`. Do not declare as an array.
- Add a new private data member to store the *capacity* of the bag.
- Add a function to return the capacity.
- Modify the default constructor.

  - Set the default capacity and size = `0`
  - Set the backing store equal to the null pointer

- Modify the initializer list constructor.

  - Set the bag size to the initializer list size.
  - Set the capacity to the bag size.
  - Set the backing store a free store array of size 
    equal to the bag size.

- Add a destructor.
  We didn't need to worry about this for our array, because it did not create
  any resources that needed to be managed.
  Now we have data on the free store (created with `new`, that doesn't get
  cleaned up until we say so.

  Use the `delete` operator to reclaim the memory allocated on the free store.

Now we are ready to start making our former array class into a bag.

### 3. Conversion constructor
Add a 1 argument constructor for a bag:

```cpp
explicit bag(size_t size);
```

Use the size to set the bag size and capacity and to set the backing store size.
- fill the bag with default values.

### 4. Copy constructor
Implement a constructor to make a `bag` from an existing one.

```cpp
bag(const bag<T>& other);
```

Use the information in the *other* bag to create this one:
- Use the other size to set the bag size.
- Use the other capacity to set the bag capacity.
- Use the capacity to set the initial free store array size.
- Use `std::copy` to copy the other data to the new bag.

### 5. Copy assignment
Implement an assignment overload to replace a `bag`s contents with
 an existing one.
Note that unlike the copy *constructor*, the current object already exists
and has data stored in it.
The goal is to clean it up, then replace the contents using the data
in the *other* bag.

```cpp
bag<T>& operator=(const bag<T>& other);
```

When done with this step, you should also check your copy assignment
does not leak memory by running the test through valgrind on buffy.
First, cd into your build directory, then:


```
valgrind --leak-check=full test/step5
```

### 6. Function `main`
Write a main function that uses each of your `mesa::bag` functions at least once.


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
[rate this lab](https://forms.gle/V1M945hZYY1bvMSC8).
