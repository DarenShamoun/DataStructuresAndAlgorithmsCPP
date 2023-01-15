# Project #2: Library Management
The goal of this project is to implement a library management program
that a library might use to manage collections and customers.

## Implementation
Implement one or more classes to manage the library collections.
At a minumum, the library should be able to manage
books, periodicals, audio, and video.

All items in the library collection should have:

- Title
- Author(s)
- Genre (fiction, non-fiction, etc.)
- Copyright date
- ISBN
- Library copy number
- Checked out / Not checked out

ISBN's are codes of the form `n-n-n-x`, 
where `n` is an integer and `x` is either a single digit or letter.

Genre should be implemented as a `scoped enum`.

Implement one or more classes to manage the members of the library,
the library Patrons.

All library member records must contain:

- Name
- Member id
- Items currerntly checked out with due dates
- Fees owed

Implement one or more classes to manage the library collection.
The goal here is to manage and update the contents of the
Library collections file and the Library membership status.

Ensure all data is valid - do not the program to read invalid data or allow
users to enter invalid data.


## Input and output
The program must support the following command-line arguments:

```
  Usage: library [-h] -L <file name> -P <file name>
  Options:
    -h   Show this text and exit. Optional.

    -L   Required. File name containing Library collection.
         If no file is specified, the program will exit.

    -P   Required. File name containing Library patrons.
         If no file is specified, the program will exit.
```

File format for both of the required files may be in any format
you choose, as long as all the required information is
stored and can be read when the program starts.

A critical objective is to not lose any library information.

Once the library is loaded, the program should provide a librarian
with choices to modify the library, or print reports:

- Add items to the library collection
- Add new library patrons
- Checkout and return items
- Print reports

  - Users who owe fees
  - Items on the waitlist
  - Patrons on the waitlist


### Checkin and checkout requirements
This is the most important part of the library.

- Do not allow members to checkout items that do not exist.
- Do not allow members to checkout items that are already checked out.

  Add these patrons to a waitlist for the item.

- Do not allow users to checkout items if they owe fees.

## Turn in checklist
All projects will be graded according to the project rubric in Canvas.

Before uploading your project,
make sure it meets all of the rubric criteria in order to get full credit.

1. Ensure all project requirements are met and all results are correct.
2. Project rubric requirements for correctness, clarity, design,
   and coding are met or exceeded.
3. Ensure the intent behind every program element is "crystal clear".
   Add documentation where it makes sense to do so.
4. Source code contains no global variables.
   Globals created as side effects of using library functions are OK (getopt, etc.).
5. Ensure the top of each source file includes your name and student ID.
6. Your finished project must compile on buffy.

## Project Requirements
In order to receive full credit, your project must satisfy **all**
of the following requirements:

1. Process command line arguments as described in *Input and output*.

   Ensure all interactions with users are correct and
   perform all library management functions.

2. Program implements the program described in the *Implementation* section
3. The program must enforce the rules of the Library.
   This includes handling error conditions.
4. No memory leaks when analyzed using valgrind on the mesa server.
5. Program functions should be small and each function should perform
   exactly one task.




