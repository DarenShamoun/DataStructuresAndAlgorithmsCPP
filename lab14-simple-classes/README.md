# Simple classes
Design and implement a few simple classes.
The goal is become comfortable writing code in a new style.
That is, encapsulating functions inside classes.

Only class `clock` needs to reside in namespace mesa.

## Steps
Ensure all class data is private and implement the following:

### 1. Create files
Create the files `classes.h` and `classes.cpp`.

### 2. Class `clock`
Define a class `clock` in file `classes.h`.
- It should have 1 member to store the time in a `double`.
- Add two functions to the class named `time`.
  One to change and one to retrieve the time.
- Implement the class in `classes.cpp`.

Don't forget to definer this in the mesa namespace.

### 3. Class `complex`
Define a class `complex` in file `classes.h`.
- Add two `double` member variables: 
  one for the real part of the number and one for the imaginary part
- Create a default constructor to initialize the number to (0,0).  
  Use initializer list syntax.
- Create a two argument constructor to initialize the number to
  `(double real, double imaginary)`.
- Add functions to retrieve the complex value components
  (real part and imaginary part) name these functions `real` and `imaginary`.
- Implement the class in `classes.cpp`.
### 4. Class `truck`
Define a class `truck` in file `classes.h`.
- Define a `uint16_t` member variable to store the number of tires on the vehicle.  
  Create a default constructor to initialize the tires to 6.
- Create a one argument constructor to initialize the tires to a provided value.
- Add a `void` function `pop_tire` that reduces the number of tires by 1.  
  Do not allow this function to reduce the number when the number of tires is already 0.
- Add a `uint16_t` function `tires` that returns the number of tires.
- Implement the class in `classes.cpp`.
### 5. Class `dog`
Create a `dog` class from the following `struct`:

```cpp
  enum class dog_size {SMALL, MEDIUM, LARGE};

  struct dog {
    std::string  name;
    dog_size sz;
  };
```

- Refactor the `struct` into a `class` in 
  file `classes.h`.  
  Make `name` and `sz` private.
- Add a constructor so that the dog name and  size can be set when a dog is created.
- Add default values for your dog class: `"Fido"` and `dog_size::MEDIUM`.
- Add functions to retrieve name and `dog_size`.
- Add a function to change the name of a dog.
- Add a function `std::string dog::bark() const` such that:
  - `LARGE` dogs return "Woof"
  - `MEDIUM` dogs return "Ruff"
  - `SMALL` dogs return "Yip"

## Try this!
Consider writing a main that uses these classes.

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
[rate this lab](https://forms.gle/tH87uuPxH1HiPKr66).
