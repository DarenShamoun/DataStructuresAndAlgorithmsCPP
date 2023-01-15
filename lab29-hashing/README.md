# Hashing concepts guided activity
The goal of this lab is to introduce hashing concepts and collision.

Recall the `std::map` and `std::set`.
Their operations include `insert`, `find`, and `delete`.
Earlier, we looked at how binary search trees can be used to implement maps and sets.
One advantage of a BST is that the amount of memory used is proportional to 
the number of items stored.
If a BST is kept balanced, the costs of the insert, delete, and find 
operations can run in `O(log2(N))` time.
Recall that if BSTs are not balanced, the costs of the operations are `O(N)`.

The costs associated with unbalanced trees are why when in the standard library,
sets and maps are often implemented as a *self-balancing tree*, such as a 
*Red-Black tree*.

One common tradeoff in computer science is the time/space tradeoff.
In some (maybe many) cases, one can increase runtime speed at the expense of storage space.
On the flip side, one can often gain efficiency in storage at the expense of running time.

A *hash table* is a way to implement a set (or a map) using an array
instead of a tree.
As you might guess, the hash table operations are faster than their tree counterparts,
but at the expense of taking more storage space.

## Background
Consider this scenario. 
We want to store student records for any current student in the district.

Your map should store (student ID, student record) information.
Student IDs are non-negative numbers and the range
of possible student IDs goes from 0 to 999,999,999.

1. How might you build a map ADT for this scenario so that 
insert, find, and delete are `O(1)` operations?

//One way to build a map ADT for this scenario so that insert, find, and delete are O(1) operations is to use a hash table.

2. How much memory does this solution take?

//the total amount of memory required by this solution is approximately (1,000,000,000 * Average string length) bytes

Consider that there are about 30,000 currently enrolled students. 
If you implement an array of size 1,000,000,000 to store 
(student ID, student record) pairs, the array is sparse.

Certainly, the insert, delete, and find operations are O(1) with this implementation, 
but the wasted space is quite large given the number of items in the map.

If we know there are 30,000 items in the dictionary,
we could instead create an array of size 100,000 to store these items.
Note that there are still 60,000 empty cells with this approach,
but that is quite a bit smaller than 1 billion.


So, in order to insert a (student ID, student record) pair into a map of size 100,000,
we need to convert student IDs to the range [0...99,999].
That is, any stuident ID in the range 0 to 1 billion will get stored in one
of the locations in the range 0 to 99,999.
One common way to do this is to use the modulus operator:

```
location = studentID % 100000;

```

3. Consider student ID 1152436.

   In what array location would this ID be inserted?
   
   //1152436 % 100000 = 2436


Because we have limited the array size, it is now possible to have *collisions*.
A collision happens when two map items are mapped to the same location in the array.

4. What is another student ID that would be mapped to the same location as `1152436`?

//2152436 would be mapped to the same location as 1152436, since 2152436 % 100000 = 1152436 % 100000.


As useful as modulus is, how do we create a map of strings?
Such as a dictionary?
In this case, we need to convert the string into a number that will become the
array storage location.

## Writing hash functions
The mapping from an object to an integer is called the *hash function*.
There are **many** implementations of hash functions. 

A good hash function:

- Spreads keys across the range of integers as evenly as possible.
- Is fast to compute, given the length of the key.
- Maps the strings (for example) "abc" and "cba" to different integers.

  Permutations of the same set of letters have different hash values.

Another property of a good hash function is that if two keys are considered equal, 
they will map to the same hash value.
For example, if uppercase "SAM" and lowercase "sam" are considered equivalent 
in your application, then they should map to the same hash value.

In order to work with the standard containers in C++,
hash functions must override `std::hash`:

```cpp
namespace std {
  template <>
  struct hash<char*>
  {
    std::size_t operator()(const char*& cstr) const
    {
      std::size_t hash_value = 3253;
      for (; *cstr != 0; ++cstr) {
        hash_value *= 28277;
        hash_value += *cstr * 2749;  
      }
      return hash_value;
    }
  };
}
```

So hashing the C string "a" is:

```
hash_value = 3253
hash_value = 3253 * 28277 // 91985081
hash_value = 91985081 + 97 * 2749 // note: 97 is 'a' in ASCII
hash_value = 92251734
```

1. Given this hash implementation,
   what is the hash for the string "ab"?

   98 is 'b' in ASCII

    hash_value = 3253
    hash_value = 3253 * 28277
    hash_value = 91985081 + 97 * 2749
    hash_value = 92251734
    hash_value = 92251734 * 28277
    hash_value = 25916481738 + 98 * 2749 
    hash_value = 25919231183


2. What is the hash value for "ba"?

    hash_value = 3253
    hash_value = 3253 * 28277 
    hash_value = 91985081 + 98 * 2749 
    hash_value = 92251734
    hash_value = 92251734 * 28277 
    hash_value = 25916481738 + 97 * 2749 
    hash_value = 25919231183

### Implementation note
Typically when writing our own hash functions, 
we want to reuse existing hash functions to the maximum
extent possible.
Hash overloads already exist for all the primitive types.
Given that, the previous hash overload could be rewritten as:

```cpp
#include <iostream>
#include <cstdlib>
#include <functional>

namespace std {   // must override std::hash
  template <>
  struct hash<char*>
  {
    std::size_t operator()(const char*& cstr) const
    {
      std::size_t hash_value = std::hash<int>()(3253);
      for (; *cstr != 0; ++cstr) {
        hash_value *= 28277;
        hash_value += std::hash<char>()(*cstr) * 2749;  
      }
      return hash_value;
    }
  };
}
int main() {
    auto a = "ab";
    auto b = "ba";
    auto hash = std::hash<char*>()(a);
    std::cout << hash << '\n';
    hash = std::hash<char*>()(b);
    std::cout << hash  << '\n';
}
```


Or in C++17 and later, even more compactly using the
hash specializations for `std::string_view`,
which can handle both std::strings and C strings:

```cpp
#include <iostream>
#include <cstring>
#include <functional>
#include <string_view>

int main() {
    auto hello = "howdy";
    auto hash = std::hash<std::string_view>()(std::string_view(hello, std::strlen(hello)));
    std::cout << hash;
}
```


# Hash tables
The array mentioned in the background section is a *hash table*.
A hash table stores data using the computed hash mod array size as
the storage location.

## Insert
Assume a hash table oif size 10 and we want to insert:

- "coconut"
- "milk"
- "apple"

First we compute the hash value for each item:

- "coconut" (hash value = 2104178476)
- "milk" (hash value = 461110994)
- "apple" (hash value = 3515030035)

Next take the modulus to determine the array index (bucket):

- "coconut" (hash % 10 = 6)
- "milk" (hash % 10 = 4)
- "apple" (hash % 10 = 5)

| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
| - | - | - | - | - | - | - | - | - | - |
|   | corn  |   | orange  | milk | apple | coconut | eggs | | |

The hash for "orange" is 3410197053.
Insert it into the above table.

Now insert "corn" - hash is 1347376851.

Now insert "eggs" - hash is 881505635.

What happens now?
This is called a *collision* - we already have a value in bucket 5.

We discuss two strategies for resolving collisions in the text.
One is *open address linear probing*.
Linear probing simply searches for the first available space if the 'proper'
bucket for a hash code is already occupied.

In this case, eggs maps to bucket 5, but is already filled.
Position 6 is also filled, but 7 is available, so we store the data there.
Do that now.

One drawback of linear probing is that the runtime for insertion can now go
to O(N) instead of O(1) for a hash table of size N. 
A second drawback of linear probing is that it produces primary clustering.
When keys hash to the same value, 
the sequence of looking for open spots is the same. 
Suppose two new keys hash to location 5.
Both inserts would follow the same process of looking at bucket 5, 6, 7, 8 
(and bucket 9 for the second key).
Suppose a third key hashes to location 5.
Now this would try to insert the key into bucket 5, 6, 7, 8, 9.
It would then wrap-around to looking at
bucket 0 and insert it there since bucket 0 is empty.

Although simple to implement, most hash table implementations
use more sophisticated techniques than linear probing.

## Delete
Consider this hash table:

| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
| - | - | - | - | - | - | - | - | - | - |
|   | corn |   | orange | milk | apple | coconut | eggs | potato | salad |

Let's delete the value "potato" and let's assume delete just means
setting this C string to null.

Now say we want to delete "salad" (hash = 125082698).
What do we know at this point:

- The bucket for salad is 8
- The array element at bucket 8 is null

We might conclude that salad is not in the table, but that is not correct.
We just didn't find it.

We need some sort of marker we can use to know if we need to continue searching for values.
For now let's use "D" to indicate array elements where something was deleted.
Deleting "potato" in the example then results in:

| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
| - | - | - | - | - | - | - | - | - | - |
|   | corn |   | orange | milk | apple | coconut | eggs | D | salad |

Now when we try to delete salad, we encounter the "D" in that bucket.
We use linear probing to continue to search for "salad" and find it at 9,
replacing the value with "D".

| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
| - | - | - | - | - | - | - | - | - | - |
|   | corn |   | orange | milk | apple | coconut | eggs | D | D |

Now suppose we want to delete "beans".
"beans" hashes to bucket 4.
Looking at 4 we see the value milk, so linear probing begins.
Positions 5, 6, and 7 all have values, so we continue.
Positions 8 and 9 both have "D", so we continue with wrapping around.
Finally we get to bucket 0 with is empty (null) and
we conclude that "beans" is not in the hash table.

1. Delete the value "eggs".
   Recall this hash code maps to bucket 5.

   What strings are compared during the delete operation?
   
   //apple coconut are compared to eggs

2. Now insert "mango", which also indexes to bucket 5.

   What locatrion does mango get written to?
   
   //mango gets written to bucket 0

   What strings are compared during the insert?
   
   //milk apple coconut eggs D D are all compared to mango


# Searching
Searching for items is similar to the insertion and deletion processes.
We need to hash the object, gets its hash value, and map it to the hash table location.
We look at that location.
If it is empty, we return a value larger and our hash table.
`size()` or a constant value larger than any possible hash table are possibilities.

If it has what we are looking for, then we return the location (or the actual contents).
Else, we go to the next bucket and continue this process.

| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
| - | - | - | - | - | - | - | - | - | - |
|   | corn |   | orange | milk | apple | coconut | mango | D | D |


1. Find "corn".
   How many string comparisons are performed?
   
   //one comparison

2. Find "mango".
   How many string comparisons are performed?

   //three comparisons

3. Find "eggs".
   How many string comparisons are performed?

   //eight comparisons


# Chaining
Chaining is an improvement over linear probing, but is a bit more complex.

Given a hash table with 10 elements and the following data:

- "table" (hash value = 944611085)
- "car" (hash value = 401203259)
- "truck" (hash value =2173423306)
- "spoon" (hash value = 4169904816)
- "cup" (hash value = 1955867221)
- "chair" (hash value = 1637910816)
- "couch" (hash value = 3993966603)
- "picture" (hash value = 3936368289)

1. Insert the data into their proper buckets using chaining.

**0**: 
**1**: 
**2**:
**3**: 
**4**:
**5**: truck
**6**: 
**7**: chair, picture
**8**: cup
**9**: table, car, spoon

2. Now repeat the process, but use open address linear probing to insert:

| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
| - | - | - | - | - | - | - | - | - | - |
| "picture"  | "cup"  |   | "couch"  |   | "table"  |  "truck"  | "spoon"  | "chair"  | "car"  |

3. Suppose we decide to use a second hash function for collisions.
The second hash function is the length of the key.
**Note** that this is a **really BAD** hash function, 
but it is something you can compute easily.
Show the contents of the hash table after "cup" has been inserted.


| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
| - | - | - | - | - | - | - | - | - | - |
| "cup"  | "picture"  |   | "couch" |   | "table"  | "truck"  | "spoon"  | "chair"  | "car"  |

4. What happens when we insert "chair"?

This is why it is a good idea to create hash tables that have prime number sizes.
You will try different sets of locations each pass through the table.

//it is pushed to bucket 8  
