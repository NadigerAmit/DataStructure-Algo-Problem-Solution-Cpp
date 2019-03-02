#include<stdio.h>
#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main() {
	stack<string> stkStr;
	stkStr.push("OM");
	stkStr.push("Shree");
	stkStr.push("GaneshayaNamah");
	stkStr.push("Jai Bajarang Bali");
	string top = stkStr.top();
	cout<<stkStr.top() <<"\n";
	cout<<stkStr.size() <<"\n";
    stkStr.pop();
	cout<<"New top after pop " <<"\n";
	cout<<stkStr.top() <<"\n";
	stkStr.push(top);
	cout<<"New top after push " <<"\n";
	cout<<stkStr.top() <<"\n";
	return 0;
}

/*
Container	           Insertion	                  Access	            Erase	                Find	             Persistent Iterators
-------------------------------------------------------------------------------------------------------------------------------------------------
vector / string	        Back: O(1) or                  O(1)	              Back: O(1)            Sorted: O(log n)      	     No
                       O(n)Other: O(n)	                                  Other: O(n)            Other: O(n)
-------------------------------------------------------------------------------------------------------------------------------------------------

deque	               Back/Front: O(1)               O(1)	              Back/Front: O(1)       Sorted: O(log n)        	Pointers only      <= implemeted using list	
                        Other: O(n)                                       Other: O(n)            Other: O(n)  
-------------------------------------------------------------------------------------------------------------------------------------------------

list /                 Back/Front: O(1)           Back/Front: O(1)        Back/Front: O(1)        O(n)                      Yes
 forward_list          With iterator: O(1)        With iterator: O(1)     With iterator: O(1)
                        Index: O(n)               Index: O(n)             Index: O(n)
-------------------------------------------------------------------------------------------------------------------------------------------------
set / map            O(log n)                       ----                  O(log n)                 O(log n)                	 Yes		      <= implemeted using red balck BST			
-------------------------------------------------------------------------------------------------------------------------------------------------
unordered_set/       O(1) or O(n)                  O(1) or O(n)           O(1) or O(n)             O(1) or O(n)              Pointer only     <= implemeted using hash 	
unordered_map										                                                 	
-------------------------------------------------------------------------------------------------------------------------------------------------
priority_queue       O(log n)                         O(1)                O(log n)                  -----                     -------         <= implemeted using min heap	
  
-------------------------------------------------------------------------------------------------------------------------------------------------
*/