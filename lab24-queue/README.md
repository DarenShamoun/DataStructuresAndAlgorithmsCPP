# Ring Buffer
The goal of this lab is to implement a queue in a ring buffer of fixed size.
This lab is adapted from the circular buffer exercise at 
[exercism.io](https://exercism.io).

A `queue` is a container that gives a programmer 
the functionality of a queue - specifically,
a FIFO (first-in, first-out) data structure.

A circular buffer, cyclic buffer, or ring buffer is a data structure that
uses a single, fixed-size buffer as if it were connected end-to-end.

## Steps

### 1. Create files
Create a new empty file `ring_buffer.h`.

Create a class template `ring_buffer` in the mesa namespace.

### 2. Constructors and read/write functions
Define a private fixed size std::array to hold your ring buffer data.

Create a default constructor and 
functions to read and write to the ring buffer:

```cpp
T pop();
void push(const T&);
```

If the buffer is empty when `pop()` is called, then throw `std::domain_error`.

If the buffer is full when `push()` is called, then throw `std::domain_error`.

### 3. Function clear ()
This function should set the entire ring available for write.
Keep in mind, that like our bag from last week, 
there is no need to actually erase or remove anything.

The ring buffer does not need to actually *be* empty to *appear* empty.

### 4. Function overwrite()
Create a function that allows writing even if the ring buffer is full.

```cpp
void overwrite(const T&);
```

If the buffer is not full, then the behavior should be identical to `push`.

If the buffer is full, then this function should replace the **oldest**
element in the ring.

## Try this!
Write your own main function that uses your ring buffer class.

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
[rate this lab](https://forms.gle/hbM16U1WTCgf3gaP6).

