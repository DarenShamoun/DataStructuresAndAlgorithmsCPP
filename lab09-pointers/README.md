# Pointers
This exercise is intended to build your understanding of pointers and their relation to arrays.

Do not use any standard library functions in any of the functions you write for this lab.

## Steps

### 1. Create files
Create files named, `lab9.h`, `lab9.cpp`, and `main.cpp`
in the `src` directory.

Ensure your declarations reside in `lab9.h` and
your definitions reside in `lab9.cpp`.

All functions should reside in the `mesa` namespace.

### 2. Lower case
Write a function 
`void mesa::to_lower(char*)` that replaces all upper case
characters in the array provided with lower case equivalents.

Modify the array without making a copy.

Since you don't know the size of the array,
or even if this is a valid pointer, the function needs to:

1. First check if the pointer is valid.
2. Process each character until the null character is reached.
3. If the character is currently upper case, then change it to lower.

You do not need to worry about locale or
characters outside the ASCII character set.

### 3. Copy
Write a function 
`char* mesa::copy(const char* source, const size_t count)`
that copies up to `count` characters from the `source` array
into an array allocated on the free store.

Stop copying if a null character is encountered.

### 4. Count
Write a function
`size_t mesa::count(const char*, const char)`
that returns
the number of occurrences of the `char` in the array.

Stop counting if a null character is encountered.

### 5. Min
Write a function template
```cpp
template<class Pointer>
Pointer mesa::min (Pointer begin, Pointer end);
```

that the smallest value in the range provided.

- `Pointer` is a placeholder for some kind of pointer.
- The parameters begin and end define a continuous
range of values.
- If `begin` points to the same value as `end`, return `end`

### 6. Test using Valgrind
Create a file `main.cpp`.

Call each of the functions you wrote.
Keep it simple.

Consider which of the above functions allocated memory
on the free store.
When main calls this function, it is responsible for
cleaning that memory up.

When finished, 
check your main on buffy by running `valgrind`,
a memory checking program.

First create a main of your own and compile your program, 
then run it through valgrind in your build directory as:

```
valgrind src/main
```

If you properly cleaned up after your free store pointers,
you should see the following line near the end of the output:

```
All heap blocks were freed -- no leaks are possible
```

Otherwise,
you see information indicating memory leaks or other memory related errors.

If you have errors, then fix them.

If you have more questions about using valgrind,
refer to the textbook.

Check the step3 program with `valgrind` by running:

```
ctest -T memcheck -R step3
```

or manually as:

```
valgrind --leak-check=full test/step3
```

in your build directory.


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
[rate this lab](https://forms.gle/uKK4U8rwvALgJqKC7).

