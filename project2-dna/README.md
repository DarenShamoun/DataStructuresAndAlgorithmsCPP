# Extra credit project: DNA Manipulation
A key element in many bioinformatics problems is the biological sequence. 
A biological sequence is just a list of characters chosen from some alphabet. 
Two common biological sequences are DNA 
(composed of the four characters A, C, G, and T) and RNA 
(composed of the four characters A, C, G, and U). 
In this project, you will implement some basic functionality for 
manipulating DNA and RNA sequence fragments.


## Implementation
Implement a class to store a single DNA or RNA sequence fragment.
The class should store the character sequence and the sequence type.

In addition to the sequences, 
define a second class containing multiple DNA sequences.
This "fragment list" stores the various sequences and must be fixed size. 
Commands that manipulate sequences will refer directly to entries in the fragment list. 

The sequence type field should use an enumerated type, 
and you should also include an enumeration value to recognize that a given 
position in the fragment list is unused.

The primary design consideration for this project will be the interface between 
the sequence class and its client.  
It is mandatory that the sequence and fragment list classes remains application independent. 

## Input and output
The program must support the following command-line arguments:

```
  Usage: sequencer [-h] [-m #] [-l log_level] -f <file name>
  Options:
    -h   Show this text and exit. Optional.

    -m   Optional. Max amount of space allocated for sequence fragments.
         The default is 8

    -l   Optional. Set the log detail level.
         The default is 'info'

    -f   Required. File name containing commands for the sequencer
         The file should be plain text, 1 command per line
         If no file is specified, the program will exit.
```

The input for this project will consist of a series of commands 
(some with associated parameters, separated by spaces), 
one command for each line in the file. 
A blank line may appear anywhere in the command file, and any number of spaces may separate parameters. 

A line beginning with `#` is considered a comment and should be printed 'as-is' to standard output.

You need not worry about checking for syntax errors in the file, but
commands must be case insensitive. 
That is, only the specified commands will appear in the file, and 
the specified parameters will always appear. 
However, you **must range-check all input parameters**. 
As part of the grading process, 
I will provide input files that will attempt to get your program to generate errors.  
Your code must protect against these types of errors.

The commands will be read from an input file, and 
the output from the commands will be written to standard output. 
The program should terminate after reading the last line of the file (EOF mark). 

## Sequence Types
Sequences come in 2 flavors:

1. **DNA** - the DNA strand
2. **RNA** - the RNA strand

Each sequence contains at most 4 unique letters:

| DNA | RNA |
| --- | --- |
|  A  |  A  |
|  C  |  C  |
|  G  |  G  |
|  T  |  U  |

## Command API
The commands used in the input file are described in the following subsections.
Example command files can be found in the `src` directory.

### insert pos type sequence
Insert the sequence at position *pos* in the fragment list. 
The type will be either **DNA** or **RNA**. 
You must check that sequence contains only appropriate letters for its type, 
if not the insert operation is in error and no change should be made to the sequence list. 

If there is already a sequence at *pos* and if sequence is syntactically correct, 
then the new sequence replaces the old one at that position. 
It is acceptable that sequence be null (contain no characters) in which case an empty sequence 
will be stored at *pos*. 

**Note:** an empty *sequence* in a position is different from a position with no sequence stored.

### remove pos
Remove the sequence at position *pos* in the fragment list.
Be sure to set the sequence type to indicate that this position is now empty. 
If there is no sequence at *pos*, output a suitable message.

### print
Print out all sequences in the fragment list. 
Indicate for each sequence its position within the fragment list and 
the type of that sequence (RNA or DNA). 
Don't print anything for slots in the fragment list that are empty. 

### print pos
Print the sequence and type at position *pos* in the fragment list.
If there is no sequence in that position, print a suitable message.

### clip pos start
Replace the sequence at position *pos* with a clipped version of the sequence. 
The clipped version is that part of the sequence beginning at character *start* and 
continuing to the end of the original sequence. 

It is an error if start is less than zero or beyond the end of the sequence.
A clip command with an error should make **no change** to the sequence
and display a suitable message. 
If there is no sequence at this slot, output a suitable message.

### copy pos1 pos2
Copy a sequence from position *pos1* to *pos2*.
If there is no sequence at *pos1*, 
output a suitable message and do not modify the sequence at *pos2*.

### swap pos1 start1 pos2 start2
Swap the tails of the sequences at fragment positions *pos1* and *pos2*.
The tail for *pos1* begins at character *start1* and 
the tail for *pos2* begins at character *start2*.
It is an error if the value of the start position is greater than the 
length of the sequence or less than zero. 
If the length of a sequence is *n*, the start position may be *n*, 
meaning that the tail of the other sequence is appended 
(i.e., a tail of null length is being swapped). 
The swap operation should be reported as an error if the two sequences are not of the same type, 
or if one of the slots does not contain a sequence. 
In either case, no change should be made to the sequences.

### transcribe pos
Transcription converts a **DNA** sequence into an **RNA** sequence.

To transcribe a sequence from **DNA** to **RNA**:

1. Change its type field to **RNA**,  
2. Complement all the letters in the sequence using the table below, and 
3. Reverse the sequence. 

**DNA to RNA Complements Table**

| DNA |     | RNA |
| --- | --- | --- |
|  A  | --> |  T  |
|  C  | --> |  G  |
|  G  | --> |  C  |
|  T  | --> |  U  |


If an attempt is made to transcribe RNA to DNA, then print a suitable message
and do not change the sequence.


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
5. The program must enforce the rules of the API.
   This includes handling error conditions.
6. Your finished project must compile on buffy.

## Project Requirements
In order to receive full credit, your project must satisfy **all**
of the following requirements:

1. Process command line arguments as described in *Input and output*   
2. Program implements the complete API described in the *Command API* section
3. While the program executes, it **should not prompt** for any
   additional input.
4. All DNA/RNA sequences data should reside on the free store.
5. No memory leaks when analyzed using valgrind on the mesa server.
6. Program functions should be small and each function should perform
   exactly one task.
7. Project rubric requirements for correctness, clarity, design,
   and coding are met or exceeded.



