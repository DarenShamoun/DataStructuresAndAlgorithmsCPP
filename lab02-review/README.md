# C/C++ Review
Review the core programming concepts you learned in your first semester of C or C++.

## Overview
The primary objective of this first lab is to review
programming concepts from your first semester and
to begin working with unit tests.

This is a group assignment.
Everyone will be organized into groups of 3 or 4 people.

Before you start, complete the form below and assign a role to each member in your group. 
If your group has 3 people, combine the Speaker and Reflector roles.

Everyone should perform all of these steps individually in order to familiarize 
yourself with the basics, but you are free to help eachother as you go.

The work submitted by the **Recorder** will be graded for the entire team.

| Team Role | Team Member|
------------- | -------------
**Recorder:** records all answers & questions and provides to instructor.  | (Daren Samoun)
**Speaker:** talks to instructor.  | (Jesus Cortez)
**Manager:** keeps track of time and ensures everyone contributes appropriately. | (Quan Nyguen)
**Questioner:** question actions and decisions made by the team. | (Thomas Navarrete)

## Making Change: 2.5 points, 30 minutes *maximum*
1. In your own words, without simply rewriting the code as plain text,
describe what [this function](src/change.cpp) is attempting to do: The function calculates how many items we can buy as the price increases for every item purchased.

2. Work through the logic manually (without compiling). 

   Write down the expected return value.

## (funds = 0, items = 4)
   

3. Compile and run the `test_change` program on buffy.

## What values are actually returned? (funds = 0.4, items = 3)

4. Did the actual output match your expectations?

## No the output did not match our expectations

   What do you think the problem is?

## The values for the price of the item has a long value with a nonround end which creates an error when c++ tries to evaluate the function

5. Run the example program in the 
   [sign and magnitude](https://daveparillo.github.io/cisc187-reader/c_review/types.html#sign-and-magnitude)
   section of course reader.

   Compare the exponent and mantissa for the different values. See any patterns?

   How might some representations create problems like the ones encountered in `test_change`?

## floating point representations may not be precise enough to handle calculations of extremely small or large numbers 
## ex: the value float 0.1 in biniary base 2 does not have an exact representation as it lies between two floating point values and neither can express the value exactly as it is a repeating value in binary

   Find at least 3 other values with troublesome floating point representations.

## values such as "float x = (1.0 / 3.0)", any number multiplied by pi, or something like "float x = 123456789.0" because floats only have 7 digits of precision

6. How many more floating point numbers with approximate representations
   do you think you could find, if you looked?
  
## infinite numbers of values that could possibly overflow and cause errors as any irrational result could result in a loss of data during calculation and therefore an error

   What is the key programming 'lesson learned' here?

## do not use floats when exact values for calculations or equality checks are needed, for example in a loop exit condition, or if you must do so code in safegaurds against this type of error.

7. Fix the code in `change.h` and `change.cpp` so that it passes the tests.

## Code reading: 1 point, 30 minutes *maximum*
For each of the problems that follow,
describe the intended program output, if any, and
whether the program compiles or not.

If it doesn't compile or produces unintended output,
then describe what changes could be made to fix it?

**Reading #1**

```cpp
#include <iostream>
#include <string>

int main () {
  const std::string dudes[4] = {"paco", "fred", "connor", "shoney"};
  for (int i = 0; i <= 3; ++i) {
    std::cout << dudes[i] << '\n';
  }
  return 0;
}
```

What is the output?
## The output is paco fred connor shoney but the loop has prints out garbage values as it has stepped out of bounds.
What is the problem (if any) and what needs to change to fix it?
## the problem is that the loop steps out of the array so the fix is to change the condition check to 3 instead of 4

**Reading #2**

```cpp
#include <iostream>

int main () {
  double x;
  double y = x;
  double z = 2.0 + x;

  std::cout << y << " and " << z << ".\n";
  return 0;
}
```

What is the output?
## 4.65576e-310 and 2
What is the problem (if any) and what needs to change to fix it?
## The problem is that x was never initialized with a value so trying to assign the value of x to y while it was never initialized with a vlaue results in undefined behavior where neither z or y will have a known value.

**Reading #3**

```cpp
#include <iostream>
#include <string>

int main () {
  int sa[2][4] = {{1,2,3,4}, {5,6,7}};

  std::cout << "first: " << sa[0][0] << '\n';
  std::cout << "last:  " << sa[1][2] << '\n'; 
}
```

What is the output?
## error too many initializers for int[3]
What is the problem (if any) and what needs to change to fix it?
## The problem was that the array was incorrectly initialized and also that the cout functions were trying accessing out of bounds memory

## Expressions: 0.5 points, 30 minutes
For each expression below, write the result and describe the expression in plain english,
for example:

```cpp
double x = 2 * (2+3);
```

`x = 10`. *Add 2 and 3 and then multiply the result by 2.
Assign the result to x.*

If an operator appears unfamiliar to you, refer to
https://en.cppreference.com/w/cpp/language/expressions#Operators

a.  
```cpp
double x = 5 + 1/2;
```
## x = 5 divide 1 by 2 and add the result to 5 but because it is integer division "1/2" is equal to zero and the answer is only 5

b.  
```cpp
double x = 5 + 1/2.0;
```
## x = 5.5 divide 1 by 2.0 which is implicitly converted to double so 1/2.0=0.5 and 5 will also be implicitly converted to double ->5.0+0.5=5.5
 

c.  
```cpp
double x = 5 + 2^3;
```
## the ^ operator is a bitwise xor operation which compares the bit values which in this case, 
## because addition has higher preceidence than xor the 5 and 2 would be added and then the xor operation would take place comparing the resulting 7 with 3
## which would look like 
## 111
## 011
## 100 would be the result which would be 4 when converted to decimal

d.  
```cpp
double x = (int) 5.0 << 1;
```
## x = 10 edits the binary representation of 5 by moving the bits to the left once

e.  
```cpp
auto x = 5 & 2;
```
## x = 0 compares the two binary values for 5 and 2 and places a 1 where the values have common digits in each position

f.  
```cpp
auto x = 5 | 2;
```
## 7 compares the two binary values for 5 and 2 and places a 0 where the values have common digits in each position

## Turnitin
Check your progress by running `make test` or `ctest -V`.

- Add your new and modified source files: 
  ```console
  git add src README.md
  ```
- Save your changes: 
  ```console
  git commit -m 'finish lab2'
  ```
- Submit your work for grading: 
  ```console
  git push
  ```

## Reflection
When you are done, take a moment to [rate this lab](https://forms.gle/mysDh7AUxo1nBA8Y8).

