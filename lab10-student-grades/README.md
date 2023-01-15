# Student Grades
This exercise is intended to build your understanding of
using vectors of pointers and
to use more complicated pointer syntax.

The main objective is to complete a program that
computes average student grades read in from a file.

Some of the code has been written already.
Your job is to fill in the remaining code.

Do not edit the `.h` files.
They define the interface, which is complete.
You are responsible for completing:

```
main.cpp
average.cpp
student.cpp
```

Most of your code should be in `student.cpp`.

Do not prompt for input.
The code provided is intended to read input from
`standard input`, for example:

```
src/grades < src/class.txt
cat src/lass.txt | src/grades
```

Both have the same effect.
Each sends the *standard input* into your program.

## Steps

### 1. Function average
Implement the average function declared in `average.h`.

Implement it in `average.cpp`.

### 2. Stream a student
Implement in `student.cpp` the `operator<<` overload
to stream a single student.

Stream a student with a single tab character between each output item,
for example:

```
Name:\tstudent name\tId:\tstudent id . . .
```

**Print grades to 2 decimal places.**

**Also important:**

To account for the simplicity of the step 2 unit tests,
make sure the last character pushed to the output stream
is the newline character.

### 3. Stream a vector of students
Implement in `student.cpp` the `operator<<` overload
to stream a `vector<student*>`.

This function should loop on each vector element and
call the overload from the previous step.

### 4. Function `add_student`
Implement in `student.cpp` the `add_student` function.

Add a single student from the provided `std::istringstream` to the vector.

### 5. Function `load_classroom`
Finish in `student.cpp` the `load_classroom` function.

### 6. Function `main`
Implement a main that uses `load_classroom` and 
your stream classroom overloads.
There should be no loops in main to do this.

When complete, the program should produce the following results
when run from the `build/src` directory:

```
# ./grades < class.txt
Name:   Alice   Id:    12345    Avg:    87.31
Name:   Bob     Id:    67890    Avg:    85.89
Name:   Clara   Id:    98765    Avg:    85.58
Name:   Doug    Id:    65432    Avg:    81.67
Name:   Elise   Id:    321456   Avg:    78.64
Name:   Fred    Id:    876345   Avg:    77.8
```

### 7. Cleanup classroom pointers
Before main exits, 
cleanup all the pointers in `main` that were returned by
`load_classroom`.

Run it through valgrind in your build directory as:

```
valgrind src/grades < src/class.txt
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
