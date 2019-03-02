#include<stdio.h>
#include<iostream>
#include<set>
#include<vector>
using namespace std;

int main() {
	set<int> setInt = {1,8,4,6,5,12,7};
	setInt.insert(-1);
	setInt.erase(8);
	for(auto value:setInt) {
		cout<<value <<endl;
	}
	return 0;
}
/*
set vs map in C++ STL
set and map in STL are similar in the sense that they both use Red Black Tree (A self balancing BST). Note that the time complexities of search, insert and delete are O(Log n).

minumim element is always at the top.

Differences:
The difference is set is used to store only keys while map is used to store key value pairs. For example consider in the problem of 
printing sorted distinct elements, we use set as there is value needed for a key. While if we change the problem to print frequencies of distinct
 sorted elements, we use map. We need map to store array values as key and frequencies as value.
 
 Red black tree:
 A red-black tree is a binary search tree with one extra bit of storage per node: its color, which can be either RED or BLACK. 
 
 A binary search tree is a red-black tree if it satisfies the following red-black properties:

1. Every node is either red or black.

2. Every leaf (NIL) is black.

3. If a node is red, then both its children are black.

4. Every simple path from a node to a descendant leaf contains the same number of black nodes.
*/

/*
Container	           Insertion	                  Access	            Erase	                Find	             Persistent Iterators
-------------------------------------------------------------------------------------------------------------------------------------------------
vector / string	        Back: O(1) or                  O(1)	              Back: O(1)            Sorted: O(log n)      	     No
                       O(n)Other: O(n)	                                  Other: O(n)            Other: O(n)
-------------------------------------------------------------------------------------------------------------------------------------------------

deque	               Back/Front: O(1)               O(1)	              Back/Front: O(1)       Sorted: O(log n)        	Pointers only
                        Other: O(n)                                       Other: O(n)            Other: O(n)  
-------------------------------------------------------------------------------------------------------------------------------------------------

list /                 Back/Front: O(1)           Back/Front: O(1)        Back/Front: O(1)        O(n)                      Yes
 forward_list          With iterator: O(1)        With iterator: O(1)     With iterator: O(1)
                        Index: O(n)               Index: O(n)             Index: O(n)
-------------------------------------------------------------------------------------------------------------------------------------------------
set / map            O(log n)                       ----                  O(log n)                 O(log n)                	 Yes					
-------------------------------------------------------------------------------------------------------------------------------------------------
unordered_set/       O(1) or O(n)                  O(1) or O(n)           O(1) or O(n)             O(1) or O(n)              Pointer only
unordered_map										                                                 	
-------------------------------------------------------------------------------------------------------------------------------------------------
priority_queue       O(log n)                         O(1)                O(log n)                  -----                     -------
  
-------------------------------------------------------------------------------------------------------------------------------------------------
*/