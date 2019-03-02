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




