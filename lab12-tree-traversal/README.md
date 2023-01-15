# Recursive Binary Tree Traversals

The goal of todays lab is to explore tree traversals
other than preorder.

## Steps

### 1. Copy files
Copy your lab11 tree.h and tree.cpp files into the lab12 `src` directory.

### 2. Template `mesa::post_order`
Implement the function template 

```cpp
void post_order (std::ostream&, const mesa::tree<T>*);
```

that extracts a `mesa::tree` into a stream, but does it in the reverse
order of `operator<<`.

### 3. Template `mesa::in_order`
Implement a function template that extracts a tree into a stream
using inorder traversal.

```cpp
void in_order (std::ostream&, const mesa::tree<T>*);
```


### 4. Template `mesa::level_order` 
Implement a function template that extracts a tree into a stream
using level order traversal.

```cpp
void level_order (std::ostream&, mesa::tree<T>*);
```

**Note:**
- This template should be **not** implemented recursively.
- The second argument is a non-const pointer.

### 5. Function `main`
Write a main function that uses each of your traversal functions at least once.

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
[rate this lab](https://forms.gle/eJZcthZ4iuVaJ6Qz7).

