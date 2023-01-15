# Sort Detective
The goal of this lab is to use a program which allows you to measure
the behavior of 7 different sorting algorithm implementations.
It runs the selected sort and displays
total number of comparisons,
total data movements, and
total execution time in milliseconds.
You must apply your understanding of the general properties of the algorithms
(and in some cases of the code used to implement them)
to determine which algorithm is associated with each sort option.

A secondary objective of this lab is for you to gain experience writing a concise,
but complete analysis of a system.

## Game Plan
As you alerady know,
if you double the size of the data set that you give to a quadratic algorithm,
it will do four times the work.
In contrast, an `O(n log n)` algorithm will do a bit more than twice as much.
A linear algorithm will do only twice as much work.
Also recall the characteristics of the input data set can affect the expected
performance of many of our sorting algorithms.
For example, some algorithms perform differently when the data sets is nearly
sorted, perfectly sorted, or very large or small.
Before you begin the lab,
you should review the expected performance of the algorithms on various data sets.

The sorting algorithms under study this week include (in alphabetical order):

- Bubble Sort,
- Heap Sort,
- Insertion Sort,
- Merge Sort,
- Quick Sort,
- Selection Sort, and
- Shell Sort.

| **Note** |
| :--------: |
| Read all of the following before beginning |

## Steps

### 1. Explore sort program
Run the program `sort-detective` installed on the Mesa server.
It should be in your path.

Make sure you can run this program and play with it a bit.

The **first** thing you should do is run `sort-detective -h`
and understand the options available.

Notice that the sort option names do not give any indication which sort
they will execute.

### 2. Make a plan
Devise a plan which will enable you to match an algorithm to a sort name.

It may make sense to try to divide the sorts into initial groups and
then to work on each group separately.
Divide and conquer: it works for algorithms and it can work here, too.

### 3. Execute your plan
Execute your plan, taking careful notes as you go.

The SortLab does not store results from previous runs,
so it is up to you to record results as you go.

## 4. Document results
Describe the results of your experiment in a summary document.
Begin with a two column table listing each sort option by name
(alpha, beta, etc.) and the sort that goes with it.

**Ensure you justify your results!!**

- Simply listing which options perform which sorts
  is **not** enough documentation to earn credit.
- Dumping or listing a bunch of data with little or no explanation
  is **not** enough documentation to earn credit.

**Collecting data**

The program will provide the following data, as an example:

| Length (N) | Ordering | Sort  | Comparisons | Movements | Sort time(msec) |
| ---        |  ---     | ----  | ----------- | --------- | --------------- |
|32 | random | alpha | 496 | 687 | 0 |

The program can provide data as plain text,
in CSV format suitable for copying into a spreadsheet,
and in markdown format, suitable for adding to a document on GitHub.


**Writing Notes**

There is no coding in this lab.
Expect a significant portion of the lab grade will be determined by
the quality of the writing of the report.
This includes the completeness of the report,
the clarity (and grammar) of the writing, and general presentation.

Some of the sorts are difficult to distinguish.
A carefully outlined experiment may compensate for an error in these cases
if the writing makes it clear that your conclusions 
and/or guesses are substantiated by the data.

Finally, remember that your report needn't detail every experiment you ran.
Provide sufficient information to justify your conclusions.
It is possible to write a very short report that is completely correct
if your experiments are well chosen.

**Reports are not graded on length**, 
rather they are graded on **quality & correctness**. 
In fact, an extremely long report is an excellent indication you
probably don’t know what you are doing.
Plus you open yourself up to more opportunities to lose points due to mistakes.
After you discover the matching,
you might consider if there was a shorter way to arrive at your conclusion.

## Turnitin
Don't forget to commit your documents and notes when you are done.

- Add your new and modified files: `git add . . . `
- Save your changes: `git commit -m 'finish sort lab'`
- Submit your work for grading: `git push`

## Reflection
When you are done, take a moment to 
[rate this lab](https://forms.gle/MDwCzQCqRvtjGecz8).


Lab#30 Sort Detective Write up:

Bubble sort, insertion sort, and selection sort are all O(n^2) algorithms that tend to have a high number of comparisons and data movements for larger data sets. 
On the other hand, quick sort and merge sort are O(n log n) algorithms that tend to have fewer comparisons and data movements for larger data sets.
First I tested the "alpha" sort option. Based on the data collected, it appears that the sorting algorithm associated with the alpha sort option is Insertion Sort. 
This is because the number of comparisons and movements increases linearly with the size of the data set, which is a characteristic of Insertion Sort.
Additionally, the sort time also increases linearly with the size of the data set, which is consistent with Insertion Sort's time complexity of O(n^2).
	
Next I tested the "beta" sort option. Based on the data collected, it appears that the sorting algorithm associated with the beta sort option is Bubble Sort. 
This is because the number of comparisons and movements increases quadratically with the size of the data set, which is a characteristic of Bubble Sort. 
Additionally, the sort time also increases quadratically with the size of the data set, which is consistent with Bubble Sort's time complexity of O(n^2).
	
Next was the "gamma" sort option. Based on the data collected, it appears that the sorting algorithm associated with the gamma sort option is Shell Sort. 
This is because the number of comparisons and movements increases sub-linearly with the size of the data set, which is a characteristic of Shell Sort.
Additionally, the sort time also increases sub-linearly with the size of the data set, which is consistent with Shell Sort's time complexity of O(n^(3/2)).
	
For the “delta” sort, Based on the data collected, it appears that the sorting algorithm associated with the delta sort option is Quick Sort. 
This is because the number of comparisons and movements increases linearly with the size of the data set, which is a characteristic of QuickSort. 
Additionally, the sort time also increases linearly with the size of the data set, which is consistent with Quicksort’s average time complexity of O(n log n).
	
Epsilon was naturally the next option here as E follows D in the alphabet. 
Based on the information provided, it appears that the sorting algorithm called "epsilon" is a merge sort. 
This can be inferred from the fact that the number of comparisons remains constant regardless of the initial ordering of the data, 
and the number of movements increases as the initial ordering becomes more disordered. The merge sort is a comparison-based sorting algorithm 
that works by repeatedly dividing the input list into smaller sublists, sorting those sublists, and then merging them back together in a sorted manner. 
One of the characteristics of the merge sort is that it makes very few data movements, since it relies on a technique called "merging" to combine sorted sublists,
rather than swapping elements. This is consistent with the behavior observed in the experiments, where the number of movements is much lower than the number of comparisons.
	
To determine the “theta” and “zeta” apart and decide which was which, I ran multiple of the same test on each to try and discern them. 
Based on the data provided, it appears that "theta" is a sorting algorithm that makes a large number of comparisons and no movements, 
while the "zeta" sort makes fewer comparisons but a larger number of movements. This suggests that "theta" is likely a 
comparison-based sorting algorithm, such as selection sort or bubble sort, while "zeta" is likely a movement-based sorting algorithm, 
such as insertion sort or heap sort. Considering that all the other options are exhausted this means that the “theta” sort was most likely a selection sort.
This by default would make “zeta” a heap sort.
	

So my final answer is that:
Alpha is an insertion sort
Beta is a bubble sort
Gamma is a shell sort
Delta is a quick sort
Epsilon is a merge sort
Zeta is a heap sort
Theta is a selection sort
