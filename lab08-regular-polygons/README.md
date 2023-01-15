# Regular polygons
The purpose of this lab is to 
explore templates in more detail.

**Remember**

Keep your functions simple.

Work on your functions one step at a time.
Don't move to the next step until all the tests from the current step pass.

## Steps

### 1. Create files
Create a file named, `lab8.h`
in the `src` directory.

This lab does not require any `.cpp` files.
Feel free to create a `main.cpp` if you want
to write your own calls to the lab functions,
but do *not* add a `main()` to lab8.h.

All functions should reside in the `mesa` namespace.

### 2. Circle area
Create a template to compute the area of a circle.

```cpp
template <class T>
constexpr double area(const T radius);
```

Assume the type `T` will pass the test for 
[std::is_arithmetic](https://en.cppreference.com/w/cpp/types/is_arithmetic).

**Note:** 
As a `constexpr` function,
C++11 will not allow adding code to check the invariants of
the radius.

### 3. Polygon perimeter
Create a template to compute the perimeter of a regular polygon.

```cpp
template <class T>
double perimeter(const T length, int16_t num_sides);
```

Remember to check for the invariants of perimeter.

**Note:** The test for this step must compile without warning,
or the test will fail to compile.

The general formula for perimeter of a regular polygon:

  ![p = sn](https://latex.codecogs.com/svg.latex?p%20%3D%20sn)

where:

  `s` = length of a side  
  `n` = number of sides

### 4. Apothem
The apothem is the shortest line from the polygon center to a side.
It will always be a perpendicular bisector of a side.

<a title="Wrtlprnft [CC BY-SA 3.0 (http://creativecommons.org/licenses/by-sa/3.0/)], via Wikimedia Commons" href="https://commons.wikimedia.org/wiki/File:Apothem_of_hexagon.svg"><img width="256" alt="Apothem of hexagon" src="https://upload.wikimedia.org/wikipedia/commons/thumb/7/73/Apothem_of_hexagon.svg/256px-Apothem_of_hexagon.svg.png"></a>

*Apothem of a hexagon*

Create a template to compute the apothem of a regular polygon.

```cpp
template <class T, int16_t num_sides>
double apothem(const T length) 
```

**Note:** The test for this step must compile without warning,
or the test will fail to compile.

A general formula for the apothem of a regular polygon:

  ![a = s / 2tan(pi/n)](https://latex.codecogs.com/svg.latex?a%20%3D%20%5Cfrac%7Bs%7D%7B2%5Ctan%20%5Cleft%20%28%20%5Cfrac%7B%5Cpi%20%7D%7Bn%7D%20%5Cright%20%29%7D)

**Note:**

All the trig functions in C++ (and most other languages) use angular units in radians,
not degrees, so the argument to the
tangent function is 
![pi over n](https://latex.codecogs.com/svg.latex?%5Cinline%20%5Cfrac%7B180%7D%7Bn%7D%5Ccdot%5Cfrac%7B%5Cpi%7D%7B180%7D%20%3D%20%5Cfrac%7B%5Cpi%7D%7Bn%7D)
instead of
![180 over n](https://latex.codecogs.com/svg.latex?%5Cinline%20%5Cfrac%7B180%7D%7Bn%7D)

### 5. Area
Create a function template to compute the area of a regular polygon.

```cpp
template <class T, int16_t num_sides>
auto area(const T length) -> decltype(length * 1.0f) { . . .
```

Use the perimeter and apothem templates written in the previous steps to
compute the area.

This function should compute the area of a regular polygon with an arbitrary number of sides.

**Note:** The test for this step must compile without warning,
or the test will fail to compile.

Once you have the apothem and perimeter, the area is:

  ![area = ap over 2](https://latex.codecogs.com/svg.latex?area%20%3D%20%5Cfrac%7Ba%5Ccdot%20p%7D%7B2%7D)

where:

  `a` = apothem  
  `p` = perimeter

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
[rate this lab](https://forms.gle/rAF4ngFMqbH1bJHaA).

