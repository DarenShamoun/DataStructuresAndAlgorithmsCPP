# Compiling
Use these instructions to compile and run the assignments you create.

More details can be found in the [course reader](http://localhost:8000/back-matter/app-a/toctree.html).

## Prerequisites
To complete your assignments, you will need:
- a GitHub account
- a git client
- cmake and a C++ toolchain

The GitHub account you need to make yourself.

If you plan to complete all your work on the campus server,
then you are all set.
All the software you need is already installed.

If you plan to work on a personal computer, then
install git from https://git-scm.com/downloads

Install a C++ Toolchain.
Exactly what you install will vary based on what you 
have learned to use in the past and 
on your computer operating system.

When in doubt, use the campus server.

For those using MS Windows:

[CodeBlocks](http://www.codeblocks.org/) 
is a simple, free, and cross platform IDE.

[CLion](https://www.jetbrains.com/clion)
is a simple, non-free, and cross platform IDE.

## Compiling and running tests
Lab build files are generated using 
[CMake](https://cmake.org).

Once you have a build file generated for your particular environment,
then you may compile the software and run tests.

### GNU/Linux and related
On GNU/Linux type systems, including Cygwin,
follow these steps to make your Makefiles.

Open a terminal in this directory, then:
```
mkdir build
cd build
cmake ..
```
Then build the project:
```
make
```
and run the tests:
```
make test
```
These same steps work for MacOS X when using the default Unix Makefile generator.

### Visual Studio
Using the GUI:

These instructions work on campus.

1. Create a directory named build and open CMake GUI.
2. Select 'Browse Source' and select this folder,
   the root of all the lab source code.
3. Select 'Browse Build' and select the `build` folder.
4. In the lower left corner, select 'Configure' and
   select 'Visual Studio 16 2019 Win64' from the list of
   available generators.

   Leave the remaining selections alone and
   press 'Finish` when done.

   Don't worry (yet) if you see any warnings or errors.
5. Press 'Generate'. When finished ("Generating done")
   close CMake GUI.
6. Open the generated solution (.sln) file in Visual Studio.

Build the solution then open
Test --> Windows --> Test Explorer to view test results or rerun tests.

If this doesn't work, try
the instructions on the Microsoft site
[here](https://docs.microsoft.com/en-us/cpp/build/cmake-projects-in-visual-studio?view=vs-2017).

Select the documentation for your version of Visual Studio.

Using the Visual Studio command line:

1. Create a directory named build.
2. Open the Visual Studio Developer prompt.
   `cd` into the build directory created in the previous step.
3. Type `cmake ..`

   This should create a standard Visual Studio solution that
   you can run from the command line or the IDE.

4. Type `MSBuild lab1.sln` to build all projects in the **Debug** configuation
5. Type `ctest -C Debug` to run all tests


To remove all executable files:

```
MSBuild lab1.sln -target:Clean
MSBuild lab1.sln -t:Clean
```

To build a single test:

```
MSBuild lab1.sln -t:step1
```

To build all files in **Release** configuration,
without any Debug symbols:

```
MSBuild lab1.sln -p:Configuration=Release
# run tests
ctest -C Release
```

If this doesn't work, try
[the instructions on the Microsoft site]
(https://docs.microsoft.com/en-us/cpp/build/walkthrough-compiling-a-native-cpp-program-on-the-command-line?view=vs-2019)


### CodeBlocks
1. Create a directory named build and open CMake GUI.
2. Select 'Browse Source' and select this folder,
   the root of all the lab source code.
3. Select 'Browse Build' and select the `build` folder.
4. In the lower left corner, select 'Configure' and
   select 'CodeBlocks - MinGW Makefiles' from the list of
   available generators.

   Leave the radio selections alone and
   press 'Finish` when done.

   Campus windows computers may complain about a `sh.exe` program in your path
   outside of CodeBlocks.
   To fix this error:

   - Delete the CMake variable `CMAKE_SH` in the variables list.
   - Press 'Configure' a second time.

5. Press 'Generate'. When finished ("Generating done")
   close CMake GUI.
6. Open the generated "CBP" file in CodeBlocks.
   It should be in the build folder you pointed at in step 3.

Build the 'all' target to compile and link programs and tests.
Test cases must be run individually - 
there is no target to run all the tests.

### MacOS Xcode
Open a terminal in this directory, then:
```
mkdir build
cd build
cmake -G Xcode ..

```
To build and run targets:
1. Open the project in Xcode.
    In this repository, the file is named `lab1.xcodeproj`
2. The `ALL_BUILD`  scheme should be open by default.
    If not, then select it.
3. Build and run the `ALL_BUILD` scheme.
4. Build and run the `RUN_TESTS` scheme.
