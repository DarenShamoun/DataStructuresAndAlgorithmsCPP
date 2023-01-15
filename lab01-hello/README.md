# cisc187-lab01-hello
Getting started with the development workflow.

## Overview
The primary objective of this first lab is to ensure 
everyone has the ability to checkout assignments,
modify them, and submit them for grading.

## Step 1: Using Git
You may perform this step on any computer where you have `git` installed
or you may login to the Mesa server and perform these steps there.

1. clone your cisc187 repo: `git clone <URL>`
   - Initialize your git identity:
   
   ```
   $ git config --global user.name "Jane Doe"
   $ git config --global user.email janedoe@example.com
   ```
   
   You only need to do this once on each computer where you clone git repositories.
   
2. Edit the [Academic promise](promise.md)

  - Replace the space in the square brackets with an **x** in each checkbox area `[ ]`
    - [x] if done correctly it should look like this

3. Build and run the unit test.
   Refer to the [build instructions](COMPILING.md).
   Detailed instructions are in the [course reader](https://daveparillo.github.io/cisc187-reader/).

   **After running your tests**:

   - Fill in your name here:

     Name: Daren Shamoun

   - Type an **x** in the checkbox area

     [x] I have compiled this project and run the unit test.


4. Commit your changes:

  - `git add *.md`
  - `git commit -m 'finish lab1'`
  - `git push`

## Step 2: Using Linux
1. Login to your Mesa server account if not already logged in.
2. Clone your cisc187 repo again, if you didn't clone it on the Mesa server in Step 1
   
   - If you are using git on this server for the first time, 
     then you need to Initialize your git identity again.
     
3. Build and run the unit test
4. Edit src/main.cpp on buffy using `vi`
   
   - Write a loop that prints hello world at least twice.
   - You may make other edits if you desire
   
5. Commit your changes

## Step 2: Introducing `vim`
1. Login to your Mesa server account if not already logged in.

   OR

   Open a terminal window in Mac or Linux

   OR

   Open Git Bash on Windows

2. Run `vimtutor` and work through the entire tutorial.

It should take about an hour.

When you want to logout of the Mesa server, type `exit` at the command prompt.

## Reflection
When you are done, take a moment to [rate this lab](https://forms.gle/mGxgWw4DABPR3Hff9).
