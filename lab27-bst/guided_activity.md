# Binary search and complexity

As discussed in the text, binary trees, and especially *binary search trees*
are data structures developed with efficient search as a primary objective.

Many algorithms focus exclusively on correctness, however, search algorithms
also put a high priority on *efficiency*.
Efficiency is a one measure of how quickly an algorithm performs a task.

We all perform searches every day:

- Where is my phone?
- What is Dave's phone email address?

## What searches do you conduct?
(Use examples from the physicval or software realm).


## Sorted Lists
One example of searching for data is searching for an item in a sorted list.
When I enter your grades I search for your name in a roster, sorted by name.

What data collections do you use that are sorted in some way? 
What is the data and how are they sorted?


## Binary Search
If we have data that is sorted, searching for that data can be made more
efficient by using a technique called binary search. 
Given:

- the data is stored in sorted order in an array.
- you are looking for a particular item, called key. 

Then, you can maintain two indices in the array that get
closer and closer together to "zero in" on the key. 
The indices start out at positions 0 and the length of the array minus 1. 
You calculate the midpoint of the indices and look at the array element 
at that midpoint.
That value tells you to search to the right of that midpoint 
or to the left of that midpoint. 

Eventually, the indices will be equal or cross over each other. 
At that point, the key is found or not found. 

Examine the code in `src/search_example.cpp`. 

# Questions

1. Suppose the user types `67` when this program is executed.

   What are the recursive calls for `binary_search`?

   ```
   binary_search(67, test_data, 0, 10)
   binary_search(67, test_data, _____, ______)
   binary_search(67, test_data, _____, ______)
   // keep going until recursion stops
   ```

2. In the above execution, 
   what are the successive values of midpoint as the function makes recursive calls?

   ```
   midpoint = 5
   midpoint = 
   midpoint = 
   // keep going
   ```

3. Suppose the user types `18`.

   What are the recursive calls for `binary_search`?

   ```
   binary_search(18, test_data, 0, 10)
   binary_search(18, test_data, _____, ______)
   binary_search(18, test_data, _____, ______)
   // keep going until recursion stops
   ```

4. Suppose the `linear_search` function is called with:

   ```
   linear_search(67, test_data)
   ```

   How many vector elements are examined before the function returns?

5. How many recursive calls were made in `binary_search` to find `67`?


6. Which function do you think is faster for searching in general?

7. Is `linear_search` a recursive function? (Yes/No)

   How do we know?



Big-O running time analysis is a mathematical function that is based on the
input size `N` of the data for the program. 
In these searching algorithms, `N` is the size of the array.
Think about how much 'work' is done in linear search and
binary search given an array of `N` items.

In this case, 'work' is how many elements are examined in 
linear search for an array of length `N`. 
'work' for binary search is how many function calls 
binary search makes for an array of length `N`, 
since each function execution is a constant amount of code.

8. What is the big-O running time of linear search if there are `N` elements in
   the array? 

   O( )

9. What is the big-O running time of binary search if there are `N` elements in
   the array?

   O( )


