#include<stdio.h>
#include<iostream>
#include<queue>
//#include<string>
using namespace std;
// decendingly sorted queue.
// Always stores max elemnt in top/front of queue.
int main() {
	priority_queue<int> pQueueInt;
	priority_queue<string> pQueueString;
	pQueueInt.push(10);
	pQueueInt.push(100);
	pQueueInt.push(03);
	pQueueInt.push(111);
	cout<<"front" <<pQueueInt.top() <<endl; 
	cout<<"size" <<pQueueInt.size() <<endl;
	pQueueInt.pop();
	cout<<"After pop" <<endl;
	cout<<"front" <<pQueueInt.top() <<endl;
	cout<<"size" <<pQueueInt.size() <<endl;
	/////////////////////////////////////
	pQueueString.push("Om");
	pQueueString.push("Shree Ganeshaya namah");
	pQueueString.push("Jai");
	pQueueString.push("Bajarang bali");
	cout<<" String front = " <<pQueueString.top() <<endl; 
	cout<<" String size = " <<pQueueString.size() <<endl;
	pQueueString.pop();
	cout<<" String front = " <<pQueueString.top() <<endl; 
	cout<<" String size = " <<pQueueString.size() <<endl;
	return 0;
}
/*
A priority queue is a queue that does not have the “first in, first out” logic.

In a priority queue, you can add successive pieces of data and retrieve the one that has the “highest priority” in constant time.

So to implement a priority queue, you also need a comparison between its elements to determine which one has the “highest priority”.

In C++ you can use std::priority_queue that wraps another container (by default, std::vector). std::priority_queue uses 
operator< by default (via the function object std::less) to compare the elements. So the element of highest priority is the largest one.

std::priority_queue also accepts a custom comparator to replace std::less. 
For instance you could use std::greater so that the element of highest priority is the smallest one. 
Or you could also use a custom comparator, to compare the keys of the elements for example, or to compare user defined types.

std::priority_queue offers the interface of a priority queue, which is:

> push: add a new element to the queue,
> pop: remove the largest element of the queue,
> top: access the largest element of the queue.

Note the difference with the interface of a simple queue: the priority queue does not give access to the element most recently inserted
(the equivalent of back in the queue). 
Instead, the elements get swallowed up by the priority queue, and it only spits out the top element.

What is link between heaps and Priority queues 

Heaps are an implementation of priority queues.
In heaps basics we saw that they offer an easy access to the largest elements, by positioning it at their root

Note : Priority queues can be implemented by heaps, and heaps can be implemented by arrays.

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




