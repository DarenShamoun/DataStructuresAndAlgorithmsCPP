# Project #1: Take away game
The goal of this project is to create a two player game called `take away`.
The games consists of one or more piles.
Typically, each pile contains stones or sticks.
In your program, you may refer to them how you like.
I will use stones.

A player may remove any number of stones from **a single pile**
when it is their turn.
The player who removes the last stone(s) wins.

## Basic Gameplay
Ask each player for their name.
The game should initialize the game with a random number of piles and 
a random number of stones in each pile.
The first player starts.
When the game is over the program should display the name of the winning player
and prompt to play another game.

The game must only allow legal moves:
- When it is a players turn they must remove at least 1 stone
- A player cannot remove more stones than are in a single pile
- A player may remove stones only from 1 pile per turn

After each player turn the game should redraw the current state of
all remaining piles.
Do not display piles with 0 stones.

## Turn in checklist
All projects will be graded according to the project rubric in Canvas.

Before uploading your project,
make sure it meets all of the rubric criteria in order to get full credit.

1. Ensure all project requirements are met and all results are correct.
2. Source code contains no global variables.
   Globals created as side effects of using library functions are OK (getopt, etc.).
3. Ensure the intent behind every program element is "crystal clear".
   Add documentation where it makes sense to do so.
4. Ensure the top of each source file includes your name and student ID.
5. The program must enforce the rules of the game.
   This includes handling error conditions.

   Don't allow users to break your game by entering invalid inputs.
6. Your finished project must compile on buffy.

## Reflection
When you are **finished**, take a moment to 
[rate this project](https://forms.gle/uGMkFTBKieq4YSrp7).

## Project Requirements
In order to receive full credit, your project must satisfy **all**
of the following requirements:

1. Process command line arguments: 

   `-h` to display `h`elp text and exit.
   `-c` to play against the `c`omputer
   `-p` to set an exact number of `p`iles
   `-s` to set an exact number of `s`tones in each pile

2. Prompt for the names of two players.
   If the `-c` switch is set, 
   then player two is automatically the computer.
   Do not prompt for the name of the computer - provide a default name.

   The computer player should always be player two.

3. If the `-p` or `-s` switches are set, 
   do not allow either parameter to be set < 1.
   You may choose to define a larger minimum value.

   You may also set a maximum value.

   If these switches are not set, then their values should be determined randomly.
   The same constraints used for manual entry apply to randomly generated values.

4.  While the program executes, it should be clear:

    a. Whose turn it is  
    b. What piles can be selected  
    c. How many stones are in each pile  

5. Program definitions and declarations must be kept in separate source files.
6. Program functions should be small and each function should perform
   exactly one task.
7. Project rubric requirements for correctness, clarity, design,
   and coding are met or exceeded.

## Implementing the computer player
Don't make this more complex than needed!

You need a minimum of 3 functions:

1. A function capable of evaluating the current state of the game.
   How many stones in each pile, etc.
   This function needs to determine what pile the computer should play and
   how many stones to take.

2. A function to return the 'which pile' determination from step 1.
3. A function to return the 'how many' determination from step 1.

How you code this is up to you, however, 
there is a simple winning strategy for this game
that can be easily implemented on a computer.

The trick is to work with the numbers of stones
as **binary** instead of decimal.

The key to the strategy is to try to make a move that results in the 
`exclusive or` of the stones in all piles is equal to zero.
For example, given a game with 3 piles with 2, 3, and 4 stones in the piles.
In binary, the game looks like:

```
    0 1 0        // binary 2
    0 1 1        // binary 3
  ^ 1 0 0        // binary 4
    -----
    1 0 1        // exclusive or of all values = binary 5
```

This result is called the *nim sum*, because this strategy was first completely described in 1901
by a mathematician, Charles Bouton, who named the game 'nim'.
The origins of this game are much more ancient, but the exact history has been lost.

Since the nim sum is greater than 0, a winning move is possible.
That is, a move that changes the nim sum of all heaps to 0 is possible.
If 3 stones are removed from the pile containing 4:

```
    0 1 0 
    0 1 1
  ^ 0 0 1
    -----
    0 0 0
```

That leaves `1 ^ 2 ^ 3`, which = 0.

This is a "winning position", because there is no move the next player can make
which will leave the piles in a state where the nim sum of all piles is zero.

When it is your turn and the nim sum is already zero, 
then there is no move you can make to guarantee a win.
The only winning strategy is to drag the game out
and hope your opponent makes a mistake.

This is a rational strategy for a computer,
because the longer a game lasts,
the more likely a human opponent will make a mistake the computer
can take advantage of.

For more information, see:

- https://plus.maths.org/content/play-win-nim
- https://en.wikipedia.org/wiki/Nim

## Example output

### Show help

```
./take-away -h
Usage: ./take-away [-h] [-c] [-p # piles] [-s # stones] 

Options:
  -h   Show this text.
  -c   Make player two the computer.  Default = false.
  -p   Manually set the starting number of piles in the game.
  -s   Manually set the starting number of stones in each pile.

       Max values for piles and stones: 99
       Min values for piles and stones: 1
```

After the help text is displayed, the program should exit.

### Default behavior
Play a random two player game.

```plain
  ./take-away
  First player name: Alice
  Second player name: Bob
  Player 1: Alice
  Player 2: Bob
  Heap 1 [ 5]: *****
  Heap 2 [14]: **************
  Heap 3 [ 8]: ********

  Alice's turn
  Which heap? 1
  How many stones? 5
  Player 1: Alice
  Player 2: Bob
  Heap 1 [14]: **************
  Heap 2 [ 8]: ********

  Bob's turn
  Which heap? 2
  How many stones? 9
     There aren't that many stones in this heap.
  How many stones? 7
  Player 1: Alice
  Player 2: Bob
  Heap 1 [14]: **************
  Heap 2 [ 1]: *

  Alice's turn
  Which heap? 1
  How many stones? 13
  Player 1: Alice
  Player 2: Bob
  Heap 1 [ 1]: *
  Heap 2 [ 1]: *

  Bob's turn
  Which heap? 1
  How many stones? 1
  Player 1: Alice
  Player 2: Bob
  Heap 1 [ 1]: *

  Alice's turn
  How many stones? 1
  Alice wins!!
  Play another game? [Y/n] n

```


### Play against the computer

```plain
  ./take-away -c 
  Human player name: Darla

  Heap 0 [15]: ***************
  Heap 1 [13]: *************
  Heap 2 [ 7]: *******
  Heap 3 [12]: ************
  Heap 4 [11]: ***********
  Heap 5 [ 9]: *********
  Darla's turn
  Which heap? 1
  How many stones? 13

  Heap 0 [15]: ***************
  Heap 1 [ 7]: *******
  Heap 2 [12]: ************
  Heap 3 [11]: ***********
  Heap 4 [ 9]: *********
  HAL 9000's turn
  HAL 9000 removed 6 stones from heap 0.

  Heap 0 [ 9]: *********
  Heap 1 [ 7]: *******
  Heap 2 [12]: ************
  Heap 3 [11]: ***********
  Heap 4 [ 9]: *********
  Darla's turn
  Which heap? 

  (rest of the game omitted)
```

## This is too hard, I need help!
If you are having difficulty getting started,
there is a set of unit tests you can use.

Compile and run the tests exactly the same we use lab tests.

These tests do not test everything.
You may add, delete, modify, or ignore these tests as you see fit.

**These steps are not required to get full credit for this project.**

They exist purely for those having trouble getting started.

They merely are the tests for *my* solution.
Your solution might be much better!

