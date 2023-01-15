# Functions
The purpose of this lab is to practice working with
function parameters and namespaces.

In this lab we will use procedural programming techniques
to create a time data structure and manipulate it
using functions.

Time can be a difficult concept on a computer, so we we will be
making several simplifications here.

- Our time struct will only have hours, minutes, and seconds.
- We are only concerned about the time in a single day.
- We are not concerned with nanosecond resolution.
- We are ignoring the hardware clock and other esoterics.

## Steps

### 1. Create files
Create files named `lab5.cpp` and `lab5.h`
in the `src` directory.

Your function declarations will reside in the `.h` file.

Your function implementations will reside in the `.cpp` file.

**All** of the code in this lab will reside in the
`mesa` namespace.

### 2. Type `time`
Create the following `struct`:
   
```cpp
// a data structure to represent the time of day
struct time_t {
  int hours;     // hours since midnight (1-12)
  int minutes;   // minutes after the hour
  int seconds;   // seconds after the minute
  char period;   // AM/PM designator
  // bitmask used to check validity and report issues
  unsigned char errors;
};
```

Define the following constants to be used in the `check` bitmask:

```cpp
constexpr unsigned char ERROR_HOUR = 1;
constexpr unsigned char ERROR_MINUTE = 2;
constexpr unsigned char ERROR_SECOND = 4;
constexpr unsigned char ERROR_PERIOD = 8;
```


### 3. Function set
Create a function with the following signature:
   
```cpp
// Set a time object using the provided parameters
void set(time_t& time, 
         int hours, int minutes, int seconds, char period = 'a');
```

Implement `set`.
Ensure invalid times are caught.

- Valid `hour` values are `(1-12)`
- Valid `minute` values are `(0-59)`
- Valid `second` values are `(0-59)`
- Valid `period` values are `a` and `p`

If an invalid parameter is detected, set the error bits
and continue to populate the time struct with the invalid data.

### 4. Function display
Create a function with the following signature:
   
```cpp
// Send time to the designated stream
void display(std::ostream& os, const time_t& time);
```

Display time in the following format:

```
H:M:S AM/PM
```

Display one of 'AM' or 'PM' depending on what period is set.

If any value is an error, then display it without modification.

If any error bits are set, display the error value in square brackets
immediately after the period (no space), for example for an invalid second:

```
12:21:99 PM[4]
```

### 5. Convert time to jiffies
The accuracy of various system calls that set timeouts, (e.g.,
select(2), sigtimedwait(2)) and measure CPU time (e.g.,
getrusage(2)) is limited by the resolution of the software clock,
a clock maintained by the kernel which measures time in jiffies.
The size of a jiffy is determined by the value of the kernel
constant HZ.

In the lab header add a const for the clock update rate:

```
#ifdef _WIN32
  const long HZ = 100;                    // user clock ticks hardcoded on windows
#elif  _WIN64
  const long HZ = 1000;                   // user clock ticks hardcoded on windows
#else
  #include <unistd.h>
  const long HZ = sysconf(_SC_CLK_TCK);   // user clock ticks / sec
#endif
```

**NOTE:**
The unix header, `unistd.h` is required for the `sysconf` function.

Create a function with the following signature:
   
```cpp
int64_t time_to_jiffies(const time_t& time);
```

If the time is valid, then convert to jiffies.

If the time is invalid, then return 0;

### 6. Convert jiffies to time
Create a function to convert jiffies to time:
   
```cpp
time_t jiffies_to_time(int64_t jiffies);
```

This function does not need to validate any data.

### 7. Function advance
Create a function to advance a clock by an amount of time.
   
```cpp
void advance(time_t& time, int hours = 0, int minutes = 0, int seconds = 0);
```

This function does not need to validate any data.

**Hint** you may find it easier to use your jiffies conversion functions
to solve this step.


## Turnitin
Check your progress by running `make test` or `ctest -V`.
This will attempt to run all tests.
Check partial progress by running the tests for a single step.
You can run tests for a single step with an IDE or ctest,
for example, `ctest -R step2`.

- Add your new and modified files: `git add src`
- Save your changes: `git commit -m 'finished lab5'`
- Submit your work for grading: `git push`

## Reflection
When you are done, take a moment to
[rate this lab](https://forms.gle/BRqfZsgapTvPdk159).

