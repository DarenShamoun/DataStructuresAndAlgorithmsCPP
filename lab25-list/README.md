# Linked list

The goal of this lab is to create a
class template that implements a linked
list of objects in memory.

Unlike an array or bag, a list never defines an initial amount
of storage to hold objects.
That is, a list never needs reserve capacity.
All list data is on the free store,
but created only when needed.

Each new link allocates memory as needed.

Because list nodes are joined by pointers, 
operations that insert nodes in the middle of a list are efficient.
Because list nodes are not adjacent in memory,
using an index to access an element directly is not possible.

## Steps

### 1. Create files
Create a file named `list.h` in the `src` directory.

### 2. Class templates
Create a template for a single node in a linked list:

```cpp
template <class T>
struct list_node {
  T value;
  list_node* next;
  explicit list_node(const T& v, list_node* next = nullptr)
    : value{v}
    , next{next}
  { }
};

```

Place this struct in the *mesa* `namespace`.

Create a class template named `list` in the *mesa* `namespace`.

Add a private member to store the **head** of the linked list.
This pointer must always point to the first node in the linked list
unless the list is empty.
For an empty list, the head node should equal the `nullptr`.

Add a private member to store the number of elements in the list.

Implement a default constructor for `mesa::list` that creates an empty list.

Add a `typedef` for the list value type.

Explicitly delete the following constructors and operators:

```cpp
list (const list&) = delete;
list (list&&) = delete;

list& operator=(const list<T>&) = delete;
list& operator=(list<T>&&) = delete;

```

We could implement them later, but we don't want to try to 
accidentally call them in the lab.

### 3. Functions `push_front` and `front` and `list(T)`
Implement a function to insert a new value at the head
of a list:

```cpp
void push_front(const T& value);
```

Keep the number of list elements updated.

Implement a function to return a reference to the head
of a list:

```cpp
T& front();
```
Implement `constexpr` and non-const versions of this function.

Create a constructor to initialize a list with a single value.

### 4. Functions `size` and `empty`
Implement functions size and empty:

```cpp
constexpr size_t size() const noexcept;
constexpr bool  empty() const noexcept;
```

which returns the number of list elements and whether the list is empty.

### 5. Function `pop_front` and `list::~list`
Implement a function `pop_front` that deletes the current list head:

```cpp
void pop_front();
```

Keep the number of list elements updated.
If the list is already empty, then do nothing.

Use `pop_front` to implement your list destructor.

Run `valgrind` to make sure your list does not leak memory.
Check the step5 program with `valgrind` by running:

```
ctest -T memcheck -R step5
```

or manually as:

```
valgrind --leak-check=full test/step5
```

in your build directory.

### 6. Function `insert_after`
Implement a function `insert_after`:

```cpp
void insert_after(const int pos, const T& value)
```

The variable `pos` is the zero-based position where
the insert will happen.
When `pos == 0`, the insert should happen after the head node.
When `pos == size-1`, the insert should create a new last node.

The last node is often called the **tail**. 
Even though our list doesn't keep track of a tail node,
many linked list implementations do for efficiency.


### Try This!
Write a main function that uses each of your `mesa::list` functions at least once.

Add copy/move constructors and copy/move assignment to your list.

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
[rate this lab](https://forms.gle/eiks6wEbzYCJGbbz8).

