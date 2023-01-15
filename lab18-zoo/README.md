# Pointer zoo

This exercise is intended to increase familiarity with
using pointers and the class concepts from the last two weeks:
virtual functions, overloads, etc.

This lab also provides more practice working with some of
the concepts used in the chain of responsibility pattern
required for the last project.

The key idea is that the `Animal`, `Pet`,
and `Robot` classes represent *interfaces*.
The `Pet` class, for example, defines an interface (a contract)
which guarantees that all implementing classes must honor.

When the `Pet` interface is passed to a function,
The function only knows about the `Pet` part of the object.
It doesn't know if the `Pet` is a
`Cat`, `Fish`, or `RoboDog`.

This is the main idea behind *runtime polymorphism*.
Not only does an implementing function not "know"
anything about classes other than `Pet`,
but it also doesn't resolve until the program runs
which function to call.

Do not edit the creatures in the zoo.
You are responsible for completing:

```
zoo.cpp
main.cpp
```

## Steps

### 1. Review existing source
This lab has several files.
Just understanding all of them takes some work (but not too much).
All the files you need already exist,
but some of them are incomplete.
The files `zoo.cpp` and `main.cpp` need some work.
You should take a few moments to understand 
what the other classes provided do.

If you don't understand something, ask.

### 2. Function `make_pets`
Implement the function `vector<Pet*> make_pets()` that creates a vector,
adds a `Cat`, `Dog`,
`Fish`, and a `RoboDog` to the vector and returns it.

### 3. Function `play_with_pets`
Implement the function 
`void play_with_pets(const vector<Pet*>&, const int16_t n)` that
contains a loop that plays with each pet **n times**.

### 4. Function `make_animals`
Implement the function 
`vector<unique_ptr<Animal>> make_animals()`
that creates a vector,
adds a `Cat`, `Dog`,
`Owl`, and a `Wolf` to the vector and returns it.

### 5. Function `treat_animals`
Implement the function 
`void treat_animals(const vector<unique_ptr<Animal>>&)` that
gives each `Animal` a 'shot'.

To give an `Animal` a shot,
just stream `make_sound()` to the standard output.


### 6. Function `main`
The code in the file `main.cpp` is incomplete.
Complete the program using the prompts in the comments provided.

In main you'll need to:
- call `make_pets` and store the return value
- play with each pet at least once.
- play with the RoboDog five more times
  - Don't make a new RoboDog to do this - use the one in the Pet vector
- print the charge remaining in the RoboDog

  The print charge remaining part is tricky:  
  > How can we print `charge_remaining`?
  >
  > The `Pet` interface doesn't have this function.

  1. We know that one of the Pets in the vector is a RoboDog.
  2. A RoboDog is both a *Pet* **and** a *Robot*
  3. We can cast *this one Pet* from a `Pet*` to a `Robot*`
     and access Robot functions.

  Casting from one object type in a class hierarchy to another is
  what `dynamic_cast` is designed to do.

- Finally, delete the free store memory allocated in the pet vector

  Ensure that when complete, no memory has leaked.

  When run through `valgrind`, it should report:

  ```
  No leaks are possible.
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
[rate this lab](https://forms.gle/Nu3QUuTe9bHTqKgZ7).
