# Stacks
The goal of this lab is to gain familiarity with the
stack abstract data type and to implement a stack
by adapting the capabilities of our bag.

The `stack` class is a container adapter that gives a programmer 
the functionality of a stack - specifically,
a LIFO (last-in, first-out) data structure.

The class template acts as a wrapper to the underlying container - only 
a specific set of functions is provided. 
A stack is designed to limit operations to a single element at a time.
A stack pushes and pops elements from the back of the underlying container,
known as the top of the stack.

## Steps

### 1. Create files
Copy your finished bag class from the previous lab.

Create a new empty file `stack.h`.

### 2. Stack as a bag adapter
Use the bag class to do all the hard work of our stack:

```cpp
template<
    class T,
    class Container = mesa::bag<T>
> class stack;
```

Create a private member of type `Container` (the default is a bag),
to function as both the backing store
and as providing the capabilities of a stack.

Create public members to store the value type
and the container type:

```cpp
typedef Container                           container_type;
typedef typename container_type::value_type value_type;
static_assert((std::is_same<T, value_type>::value), 
              "stack type must match underlying container value type" );
```

The assert guarantees that if a custom container is provided
and the container value type does not match the stack value type,
then the code will not compile.

### 3. Stack constructors
Create stack constructors:

```cpp
stack();                                   // default
stack(const stack<T>& other)               // copy constructor
stack(const container_type& other)           // copy from Container
stack<T>& operator=(const stack<T>& other) // copy assign
stack(stack<T>&& other)                    // move construct
stack<T>& operator=(stack<T>&& other)      // move assign
constexpr bool empty()   const noexcept;
constexpr size_t size()  const noexcept;
```

In each case, simply call the underlying container constructor.

While not constructors, `empty` and `size` allow for some testing.

### Step 4. Stack operations
Create 3 functions to implement the defining operations of a stack:

```cpp
T& top();
constexpr const T& top() const noexcept ;
void push(const T& value);
void pop();
```

by calling function from the underlying container.

An optional step is to add a move version of `push`

### Step 5. Stack relational operations
Create stack relational operators by using the operations
in the underlying container.
In order for the non-member relational operators to access the
container in the stack, `operator==` and `operator<` need to be
`friend` functions implemented inside the stack class:

```cpp
template <class T1, class C1>
  friend
    bool
    operator==(const stack<T1, C1>& lhs, const stack<T1, C1>& rhs);

  template <class T1, class C1>
    friend
    bool
    operator< (const stack<T1, C1>& lhs, const stack<T1, C1>& rhs);
```

Implement them in the stack class.

Because these function templates are friends of the stack class,
they have access to the private stack container,
which can be checked for equality and less than.

Even though they are implemented in the class they are 
**not** member functions.

The remaining relational operations are implemented using the usual pattern.

## Try This!
Use your stack in a main program of your own.

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
[rate this lab](https://forms.gle/3mrP7S4JgHticABn9).

