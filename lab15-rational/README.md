# Rational numbers

A rational number class.

The goal of this lab is to explore creating a class that can
begin to function like a built-in type.

A rational number is a number that can be expressed as 
a ratio of two integers,
for example:

![1 over 1 , -4 over 7 , or x over y](https://latex.codecogs.com/svg.latex?%5Cfrac%7B1%7D%7B1%7D%2C%20%5Cfrac%7B-4%7D%7B7%7D%2C%20%5Cmathrm%7Bor%7D%20%5Cfrac%7Bx%7D%7By%7D)

When today's lab and the next are complete,
we will have created a *value class*
that behaves much like a built-in type.


In all steps, ensure that your operator overloads are
member functions only when appropriate.

## Steps

### 1. Create files
Create the file `src/rational.h`

### 2. class `rational`
Create a `rational` class.

Create a default constructor.
Default the numerator to 0 and the denominator to 1.

Provide functions `numerator` and `denominator` that return the
parts of a rational.

### 3. rational constructors
Create a two argument constructor.  
Make the denominator default value = 1.

### 4. rational to double type conversion
Create 2 functions that convert a `rational` to a `double`:
- a conversion operator overload and
- a function `to_double()`

If the denominator contains 0, then return 
`std::numeric_limits<double>::infinity()`.

### 5. String conversion
Create a conversion operator overload
that converts a `rational` to a `std::string`.

The string should separate numerator and denominator with the '/' character.

No spaces.

Other requirements:
- If the numerator is zero, return "0".
- If the numerator equals the denominator, return "1".
- If the denominator is zero, return "inf".

### 6. Stream extraction
Create a `std::ostream` overload
(`operator <<`) to send a rational number to a stream.

## Try This!
Create a main that uses your rational class.

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
[rate this lab](https://forms.gle/KvF9Mk7MU6ChvpgSA).
