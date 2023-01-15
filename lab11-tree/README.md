# Recusrsive Binary Trees

The goal of this lab is to review recursive functions
in the context of a new, non-linear data structure:
a *binary tree*.

## Steps

### 1. Create files
Create files named, `tree.cpp`, `main.cpp`, and `tree.h`
in the `src` directory.

### 2. struct `tree`
Create a data structure in the mesa namespace:

```cpp
// a recursive binary tree
template<class T>
  struct tree {
    T value;
    tree<T>* left = nullptr;
    tree<T>* right = nullptr;
  };
```

### 3. Template `make_tree(T)`
Implement the function template 

```cpp
tree<T>* make_tree(T value);
```

that makes a new tree node, assigning the provided value to
the new tree node value.

Remember that because the function returns a pointer to a tree,
the tree needs to be made on the free-store.

### 4. Template `make_tree(T, tree<T>*, tree<T>*)`
Implement the function template 

```cpp
tree<T>* make_tree(T value, tree<T>* left, tree<T>* right);
```

that makes a new tree node, assigning the provided value to
the new tree node value.
The pointers to `left` and `right` should be assigned to the
new tree data members.

### 5. Template `operator<<`
Implement a function template overload for stream extraction:

```cpp
std::ostream& operator<< (std::ostream&, const mesa::tree<T>*);
```

**Notes:**

- This template should be implemented recursively.
- Use **preorder traversal** for your function.
- Checking if the tree pointer equals `nullptr` is the base case.
- For the recursive case, stream the value, followed by a single space.

### 6. Function `main`
Write a main function that uses each of your tree functions at least once.

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
[rate this lab](https://forms.gle/fEXfFVbVCF1LtETYA).
