# Functions
The purpose of this lab is to practice working with
function parameters and namespaces.


## Pass by reference and pass by value: 2 points, 30 minutes *maximum*
This exercise is taken from
*Programming: Principles and Practice Using C++*.
Addison-Wesley Professional, 2nd edition,
June 2014. ISBN: 978-0321992789.

Given 3 functions:

```cpp
 void swap_v (int a, int b);
 void swap_r (int& a, int& b);
 void swap_cr(const int& a, const int& b);
```

And given that each function has the same body:

```cpp
   {
      int temp;
      temp = a;
      a = b;
      b = temp;
   }
```

This is a simple form of the *copy and swap idiom*.

Without compiling, 
determine the output of these functions and complete the table.
Not all of the examples in the table below will compile.

- Which of these calls compile?
- Provide a brief explanation of each function call

  - If it compiles, describe the result
  - If it does not compile, explain why

Given the following definitions of `x` and `y` when passed to `swap`:

```cpp
int x = 7;
int y = 9;
```

| Definitions and Function Call | Compiles (Y/N) | Explanation |
| ---                           | ---            | ---         |
| `swap_v(x,y);`                | Y              | This compiles because the values of x and y are copied into the function and swapped but the values are not returned  |
| `swap_r(x,y);`                | Y              | This compiles and the references for these values are passed into the function and swapped with each other, changing the original values passed in |
| `swap_cr(x,y);`               | N              | This does not compile because the constant modifier on the reference variables passed prevents either of these passed in values from being changed |

And when the following literals are passed to `swap`:

| Definitions and Function Call | Compiles (Y/N) | Explanation       |
| ---                           | ---            | ---               |
`swap_v(3,5);`                  | Y              | This would work because the function is expecting an integer value not necissarily just a variable |
`swap_r(3,5);`                  | N              | This will not compile as the function needs to have reference variables passed into it not literals |

Given the following definitions of `cx` and `cy` when passed to `swap`:

```cpp
const int cx = 7;
const int cy = 9;
```

| Definitions and Function Call | Compiles (Y/N) | Explanation       |
| ---                            | ---           | ---               |
| `swap_v(cx,cy);`               | Y             | This will compile because the value being passed into the function copied for use within the function so the const keyword has no effect in this instance |
| `swap_r(cx,cy);`               | N             | This will not compile because the function is attempting to change the original values of cx and cy as it is passed the reference to them which will cause an error as they are const|

And when the following literals are passed to `swap`:

| Definitions and Function Call | Compiles (Y/N) | Explanation           |
| ---                               | ---            | ---               |
| `swap_v(3.5,8.13);`               | Y              | This program compiles because the values are type casted into int values but there is a loss of data |
| `swap_r(3.5,8.13);`               | N              | This program does not compile because the function needs to have reference variables passed into it not literals |

Given the following definitions of `dx` and `dy` when passed to `swap`:

```cpp
double dx = 3.5;
double dy = 8.13;
```

| Definitions and Function Call | Compiles (Y/N) | Explanation       |
| ---                           | ---            | ---               |
| `swap_v(dx,dy);`              | Y              | The values of dx and dy are copied and typecasted for use within the function without error |
| `swap_r(dx,dy);`              | N              | The values cannot be passed in without the const modifier as they can not be casted into int from int& |


## Debugging: 2 points, 30 minutes
Examine the program provided in the src folder.

What is the expected output? Record your answer here.

##After the swap and add the values should change to a = 21 b = 11

Now compile and run the program `src/lab5`.
What is the actual output?

##After the swap the values were only a = 20 and b = 21

What is wrong with this program?  What changes need to be made to fix it?

##The type of variables a and b needs to be changed to long so that the swap function can run 

Make your changes, make sure the program compiles and runs.
When complete, the program should print:

```
original values:
a: 10, b: 20
after swap and add:
a: 21, b: 11
```

when running with default arguments.

## Turnitin

- Add your new and modified files: `git add . . .`
- Save your changes: `git commit . . .`
- Submit your work for grading: `git push`

## Reflection
When you are done, take a moment to 
[rate this lab](https://forms.gle/BRqfZsgapTvPdk159).


