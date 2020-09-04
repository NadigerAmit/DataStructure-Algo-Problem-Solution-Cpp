# Algorithms and Data Structures in C++

C++ is a general-purpose programming language which has evolved over the years and is used to develop software for many different sectors. Using C++ we are trying to solve popular data structure and algorithms problems asked in Famous compinies (Google , Facebook , snapchat , etc)

## About Me
I am Amit Nadiger, currently working as Software Engineering manager in Japan.

https://www.linkedin.com/public-profile/settings?trk=d_flagship3_profile_self_view_public_profile

### Prerequisites

You should know basic of C,C++.
I used gcc compier for compilation , compier version: gcc version 8.1.0

### Big O , Big Omega, Big Theta Notation
#### Big O means your algorithm will execute in no more steps than in given expression

#### Big Omega means your algorithm will execute in no fewer steps than in the given expression

#### When both condition are true for the same expression, you can use the big theta notation....

****************************************************

If an algorithm is of Θ(g(n)), it means that the running time of the algorithm as n (input size) gets larger is proportional to g(n).

If an algorithm is of O(g(n)), it means that the running time of the algorithm as n gets larger is at most proportional to g(n).

Normally, even when people talk about O(g(n)) they actually mean Θ(g(n)) but technically, there is a difference.
#### Technically 
O(n) represents upper bound. Θ(n) means tight bound. Ω(n) represents lower bound.

f(x) = Θ(g(x)) iff f(x) = O(g(x)) and f(x) = Ω(g(x))

### Big O Notation

*Big O notation* is used to classify algorithms according to how their running time or space requirements grow as the input size grows.
On the chart below you may find most common orders of growth of algorithms specified in Big O notation.


Source: [Big O Cheat Sheet](http://bigocheatsheet.com/).

Below is the list of some of the most used Big O notations and their performance comparisons against different sizes of the input data.

| Big O Notation | Computations for 10 elements | Computations for 100 elements | Computations for 1000 elements  |
| -------------- | ---------------------------- | ----------------------------- | ------------------------------- |
| **O(1)**       | 1                            | 1                             | 1                               |
| **O(log N)**   | 1                            | 2                             | 3                               |
| **O(N)**       | 10                           | 100                           | 1000                            |
| **O(N log N)** | 10                           | 200                           | 3000                            |
| **O(N^2)**     | 100                          | 10000                         | 1000000                         |
| **O(2^N)**     | 1024                         | 1.26e+29                      | 1.07e+301                       |
| **O(N!)**      | 3628800                      | 9.3e+157                      | 4.02e+2567                      |

### Data Structure Operations Complexity

| Data Structure          | Access    | Search    | Insertion | Deletion  | Comments  |
| ----------------------- | :-------: | :-------: | :-------: | :-------: | :-------- |
| **Array**               | 1         | n         | n         | n         |           |
| **Stack**               | n         | n         | 1         | 1         |           |
| **Queue**               | n         | n         | 1         | 1         |           |
| **Linked List**         | n         | n         | 1         | n         |           |
| **Hash Table**          | -         | n         | n         | n         | In case of perfect hash function costs would be O(1) Ex; unordered_map,unordered_set,unordered_multimap,unordered_multiset |
| **Binary Search Tree**  | n         | n         | n         | n         | In case of balanced tree costs would be O(log(n)) |
| **B-Tree**              | log(n)    | log(n)    | log(n)    | log(n)    |           |
| **Red-Black Tree**      | log(n)    | log(n)    | log(n)    | log(n)    |  Ex; map , set,multiset ,multimap         |
| **AVL Tree**            | log(n)    | log(n)    | log(n)    | log(n)    |           |
| **Bloom Filter**        | -         | 1         | 1         | -         | False positives are possible while searching |

### Array Sorting Algorithms Complexity

| Name                  | Best            | Average             | Worst               | Memory    | Stable    | Comments  |
| --------------------- | :-------------: | :-----------------: | :-----------------: | :-------: | :-------: | :-------- |
| **Bubble sort**       | n               | n<sup>2</sup>       | n<sup>2</sup>       | 1         | Yes       |           |
| **Insertion sort**    | n               | n<sup>2</sup>       | n<sup>2</sup>       | 1         | Yes       |           |
| **Selection sort**    | n<sup>2</sup>   | n<sup>2</sup>       | n<sup>2</sup>       | 1         | No        |           |
| **Heap sort**         | n&nbsp;log(n)   | n&nbsp;log(n)       | n&nbsp;log(n)       | 1         | No        |           |
| **Merge sort**        | n&nbsp;log(n)   | n&nbsp;log(n)       | n&nbsp;log(n)       | n         | Yes       |           |
| **Quick sort**        | n&nbsp;log(n)   | n&nbsp;log(n)       | n<sup>2</sup>       | log(n)    | No        | Quicksort is usually done in-place with O(log(n)) stack space |
| **Shell sort**        | n&nbsp;log(n)   | depends on gap sequence   | n&nbsp;(log(n))<sup>2</sup>  | 1         | No         |           |
| **Counting sort**     | n + r           | n + r               | n + r               | n + r     | Yes       | r - biggest number in array |
| **Radix sort**        | n * k           | n * k               | n * k               | n + k     | Yes       | k - length of longest key |
