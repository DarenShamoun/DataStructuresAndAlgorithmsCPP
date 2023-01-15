# Heaps
The goal of this lab is to introduce a min heap
and become familiar with their properties.

A **heap** is a type of *binary tree* with the following properties:

- The tree must be **complete**
- The order of elements must obey the *heap property*

For a **min-heap** a parent element must be `<=` all its children.

For a **max-heap** a parent element must be `>=` all its children.

Although conceptually a heap is a tree-like data structure,
because the tree must be complete, it fits easily into an array.
For a tree of height
![2^h -1](https://latex.codecogs.com/svg.image?2%5E%7Bh%7D-1)

- The parent of a node `i` is located ![i over 2](https://latex.codecogs.com/svg.image?%5Cfrac%20%7Bi%7D%7B2%7D)
- The left child of a node `i` is located ![2i](https://latex.codecogs.com/svg.image?2i)
- The right child of a node `i` is located ![2i+1](https://latex.codecogs.com/svg.image?2i&plus;1)

Some of the code in this lab has been completed.
It is up to you to complete the rest.

## Note
There are many ways to construct a heap.
This lab implements the heap described in the textbook.

An important feature to be aware of is that to simplify bookkeeping,
the container element at position `0` is used for temp storage and
the root element of the tree is at position `1`.

## Steps

The files you need for this lab have already been created,
so the first step includes a unit test.

### 1. Binary heap constructor

Create default and one argument constructors.
The one argument constructor should take a `vector<T>`.

To fill heap from a vector we will need to ensure when complete
the heap elements obey the *heap property*.
An easy way to accomplish this is to put the elements in the heap in any order,
maintaining the basic tree structure - ensure the tree is **complete**.
After all the elements have been copied,
use the `percolate_down` function provided.

The build heap algorithm:

- Loop from the array mid-point down to the root node.
- For each loop iteration, pass the loop index to `percolate_down`.

make sure you allocate 1 extra space for the temp storage in position 0.

### 2. Functions `empty`, `size`, `front`, and `clear`
Create functions for the binary heap `empty`, `size`, `front`, and `clear`.
They should use the provided private members of the `binary_heap`.

### 3. Function `pop`
Remove the smallest item from the heap and use `percolate_down` to
maintain the heap property.


### 4. Function `push`
Add a new value and place it in the heap such that when complete,
the heap propoerty is still satisfied.

Algorithm:

- If the heap is full, then resize the backing store to increase capacity
- Insert the new value and 'percolate up' to determine the final position:

  - Define a new location for the new value (size() +1)
  - Store the value in the temporary storage location (`0`)
  - While the new value is less than the new location parent value:
    
    - move the parent value into the new location

  - Finally, move the temp storage into the location of the 'last parent'
    value moved.

This works, because if there were no moves, then the new value must be the largest
and it will be a leaf node.
If it is smaller than a node already in the tree, then the (larger) parent values
will be pushed down the tree until no larger node is found, and the space
created by the last parent node 'move' is where the new value can be stored.

### 5. Use `binary_heap`
Use your binary heap class in main.


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
[rate this lab](https://forms.gle/6MpBQCEFvBoKa9sr9).

