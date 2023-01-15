# Function overloads
The purpose of this lab is to 
explore some important function overloads.

**Remember**

Keep your functions simple.

Work on your functions one step at a time.
Don't move to the next step until all the tests from the current step pass.

Some functions in this lab reside in `namespace mesa`,
some are in the global namespace, and others are in `namespace std`.

Keep alert for the differences.

## Steps

### 1. Create files
Create files named, `abs.h`, `lab7.cpp` and `lab7.h`
in the `src` directory.

Part of your grade for this lab is knowing
what declarations and defintions belong in the `.h` file and
belong in the `.cpp` file.

### 2. Overload function abs
Create `constexpr` function overloads for the function `mesa::abs`.
Implement all the overloads in `abs.h`.

The `int` overload has been created for you:

```
constexpr
  int abs (const int value) {
    return value<0? -value: value;
  }
```

In C++11, a `constexpr` function may contain 
only a return statement.
The ternary operator counts as a single line.

Create overloads for the following types:

- `unsigned`
- `unsigned char`
- `int` (provided)
- `long`
- `double`
- `long long`
- `long double`
- `unsigned long`

### 3. Template abs
Implement a `constexpr` function template for `abs`.

So that you can compile and run both the overload versions
and the template version, implement the template version
in the `lab7` file.

### 4. struct point and `operator==()`
When creating even simple user defined types,
it's common to need to compare two objects
to check if they contain equivalent data.

Types that support the `==` operation
(and the `!=` operation)
are called *regular* types.

Create a `struct point` in the mesa namespace:

```cpp
struct point {
  int x;
  int y;
};
```

Implement an `inline` point overload for the equivalence operator: `operator==`:

```cpp
inline
bool operator==(const mesa::point& lhs, const mesa::point& rhs);
```

### 5. `operator!=()`
Implement an `inline` overload for the not 
equivalent operator: `operator!=`.

### 6.  `operator<<()`
Implement a point overload for the stream extraction operator: `operator<<`:

```cpp
std::ostream& operator<<(std::ostream&, const mesa::point&);
```

The output stream should enclose the point in square brackets and separate the values with a comma.
Do not add a newline character or line feed, for example if the `x` value is 2 and the `y` value is 3, then

```
[2,3]
```
should be returned from this function.

This overload is useful if you want to send your type
to standard output (`std::cout`), save it to a file,
or send it to any other output stream.

While not the most common overload, it's useful in class.


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
[rate this lab](https://forms.gle/V5sJQd427fqd6XcTA).


