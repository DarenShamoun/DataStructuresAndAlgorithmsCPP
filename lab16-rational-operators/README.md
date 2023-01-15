# Rational number operator overloads
The goal of this lab is to add math operations to rational
so that it behaves much like the fundamental types.

In all steps, ensure that your operator overloads are
member functions only when appropriate.

## Steps

### 1. Copy files
Copy the file `rational.h` from the previous lab.
You may use your own copy or my solution.

### 2. Assignment and comparison overloads
Create an operator overload for assignment. 

Create overloads for all 6 comparison overloads.
The formula for equality is:

![a over b = c over d iff ad = bc](https://latex.codecogs.com/svg.latex?%5Cfrac%7Ba%7D%7Bb%7D%20%3D%20%5Cfrac%7Bc%7D%7Bd%7D%2C%20%5Ctextrm%7Bif%20and%20only%20if%7D%20%5C%3B%20ad%20%3D%20bc)

Remember you only need to implement 'real' code in
`operator==` and `operator<`.
All other comparison operators should be implemented
in terms of other comparison functions.

### 3. Addition overloads
Create operator overloads for addition.
The formula for addition is:

![a over b + c over d = {ad + bc} over bd](https://latex.codecogs.com/svg.latex?%5Cfrac%7Ba%7D%7Bb%7D%20&plus;%20%5Cfrac%7Bc%7D%7Bd%7D%20%3D%5Cfrac%7Bad&plus;bc%7D%7Bbd%7D)

### 4. Subtraction overloads
Create operator overloads for subtraction.
The formula for subtraction is:

![a over b - c over d = {ad - bc} over bd](https://latex.codecogs.com/svg.latex?%5Cfrac%7Ba%7D%7Bb%7D%20-%20%5Cfrac%7Bc%7D%7Bd%7D%20%3D%5Cfrac%7Bad-bc%7D%7Bbd%7D)

### 5. Multiplication overloads
Create operator overloads for multiplication.
The formula for multiplication is:

![a over b times c over d = ac over bd](https://latex.codecogs.com/svg.latex?%5Cfrac%7Ba%7D%7Bb%7D%20%5Ctimes%20%5Cfrac%7Bc%7D%7Bd%7D%20%3D%5Cfrac%7Bac%7D%7Bbd%7D)

### 6. Division overloads
Create operator overloads for division.
The formula for division is:

![a over b \[u00F7\] c over d = ad over bc](https://latex.codecogs.com/svg.latex?%5Cfrac%7Ba%7D%7Bb%7D%20%5Cdiv%20%5Cfrac%7Bc%7D%7Bd%7D%20%3D%5Cfrac%7Bad%7D%7Bbc%7D)

## Try This!
Use your new rational class functions in main.

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
[rate this lab](https://forms.gle/hrdVg3GPRZjFtKH19).
