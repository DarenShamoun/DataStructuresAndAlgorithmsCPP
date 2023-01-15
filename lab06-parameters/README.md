# Passing parameters and returning values

## Overview
The purpose of this exercise is to practice passing arguments to functions
and returning values from functions.

**Remember**

Keep your functions simple.

Work on your functions one step at a time.
Don't move to the next step until all the tests from the current step pass.

## Steps

### 1. Create files
Create files named `lab6.cpp` and `lab6.h`
in the `src` directory.

Your function declarations will reside in the `.h` file and
function definitions will reside in the `.cpp` file.

For the remainder of this lab, all declarations should be placed in the 
`namespace mesa`.

### 2. Struct trigon
Create a `struct` named `trigon` to hold the lengths 
of the sides of a 3 sided polygon:

```cpp
struct trigon {
  float a;
  float b;
  float c;
};
```

Write a function `make_triple` that takes two `int16_t` constants and
returns a `trigon` that is a Pythagorean triple using Euclid's formula:

```cpp
trigon make_triple (const int16_t m, const int16_t n);
```

You need to include `<cstdint>` to use the `int16_t` type.

Use Euclid's formula to create a Pythagorean triple
from the two parameters `m` and `n`.

When `m` > `n` > `0`, the following:

  ![a = m^2 - n^2](https://latex.codecogs.com/svg.latex?a&space;=&space;m^{2}&space;-&space;n^{2})

  ![b = 2mn](https://latex.codecogs.com/svg.latex?b%20%3D%202mn)

  ![c = m^2 + n^2](https://latex.codecogs.com/svg.latex?c%20%3D%20m%5E%7B2%7D%20&plus;%20n%5E%7B2%7D)

will create a Pythagorean right triangle.

If parameter `m` is less than `n`, 
or `n < 1` the `make_triple` should return `{0,0,0}`.


### 3.  Function `scale`
Write a function `scale` that takes a `trigon` reference and
a `float` scaling factor that 
increases or decreases the size of the trigon:

```cpp
void  scale (trigon&, const float);
```

Values > 1.0 should make the trigon sides longer.

Values < 1.0 should make the trigon sides shorter.

The function should not modify the trigon if the scale factor is < 0.01.

This function should not return a value.

### 4.  Function `area`
Write a function `area` that takes a constant `trigon` reference and
returns the area of the trigon:

```cpp
float area (const trigon&);
```

To compute the area, first compute the semi-perimeter:

  ![s = \frac{a+b+c}{2}](https://latex.codecogs.com/svg.latex?s%20%3D%20%5Cfrac%7Ba&plus;b&plus;c%7D%7B2%7D)

Compute the area using the semi-perimeter:


  ![a=sqrt{s(s-a)(s-b)(s-c)}](https://latex.codecogs.com/svg.latex?area=\sqrt{s\cdot\left(s-a\right)\cdot\left(s-b\right)\cdot\left(s-c\right)})

If any side of the `trigon` is 0, then return 0 for the area.

You need to include `<cmath>` to use the `sqrt` function.

### 5.  Function `smallest`
Write a function `smallest` that takes a constant `vector<trigon>` reference and
returns the `trigon` with the smallest area.

```cpp
trigon smallest (const vector<trigon>&);
```

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
[rate this lab](https://forms.gle/6WepEpJA5QvzEuZt7).

