#include<stdio.h>
#include<iostream>
#include<deque>
using namespace std;
// double eneded queue 
// push_back(),push_front()
// pop back and pop front
// supports iterator unlike queue and stack.
int main() {
	deque<int> qdueueInt;
	deque<int>::iterator itr;
	qdueueInt.push_front(100);
	qdueueInt.push_front(101);
	qdueueInt.push_back(201);
	qdueueInt.push_back(100);
	qdueueInt.pop_back();
	qdueueInt.pop_front();
	for(itr=qdueueInt.begin();itr != qdueueInt.end();itr++) {
		cout<<*itr <<endl;
	}
	return 0;
}

/*
deque provide a functionality similar to vectors, but with efficient insertion and deletion of elements also at the beginning of the sequence, and not 
only at its end. But, unlike vectors, deques are not guaranteed to store all its elements in contiguous storage locations: accessing elements in a deque by 
offsetting a pointer to another element causes undefined behavior.

Both vectors and deques provide a very similar interface and can be used for similar purposes, but internally both work in quite different ways: 
While vectors use a single array that needs to be occasionally reallocated for growth, the elements of a deque can be scattered in different chunks of storage, 
with the container keeping the necessary information 
internally to provide direct access to any of its elements in constant time and with a uniform sequential interface (through iterators). 
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