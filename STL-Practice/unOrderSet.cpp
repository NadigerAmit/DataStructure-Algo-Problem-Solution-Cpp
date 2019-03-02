#include<stdio.h>
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

bool hasPairWithSum(vector<int> data, int sum) {
	unordered_set<int> comp ; // compliment
	for(auto value:data) {
		if(comp.find(value) != comp.end()) return true;
		comp.insert(sum-value);
	}
	return false;
}

int main() {
    unordered_set<string> compString = {"Amit","OM","Shree","GaneshayaNamah","OmJaibajarangBali"}; 	
	vector<int> data = {1,3,5,2,-1,21};
	int sum = 0;
	cin>>sum;
	bool result = hasPairWithSum(data,sum);
	cout<<"Has pair with sum " <<sum << " = "<< result;
	 cout<<"\nprinting un orderd string";
//	 unordered_set<string>::iterator itr;
//	 for(auto itr=compString.begin();itr!=compString.begin();itr++) {
	for(auto name:compString) {
		 //cout<<*itr<<endl;
		 cout<<endl<<name;
	 }
	return 0;
}

/*
What is Hashing and Hash Table? <= Please refer below link.
https://thispointer.com/what-is-hashing-and-hash-table/

set vs unordered_set in C++ STL
Pre-requisite : set in C++, unordered_set in C++

Differences :

                |     set             | unordered_set
---------------------------------------------------------
Ordering        | increasing  order   | no ordering
                | (by default)        |

Implementation  | Self balancing BST  | Hash Table
                | like Red-Black Tree |  

search time     | log(n)              | O(1) -> Average 
                |                     | O(n) -> Worst Case

Insertion time  | log(n) + Rebalance  | Same as search
                      
Deletion time   | log(n) + Rebalance  | Same as search
Use set when

We need ordered data.
We would have to print/access the data (in sorted order).
We need predecessor/successor of elements.
Since set is ordered, we can use functions like binary_search(), lower_bound() and upper_bound() on set elements. These functions cannot be used on unordered_set().
See advantages of BST over Hash Table for more cases.
Use unordered_set when

We need to keep a set of distinct elements and no ordering is required.
We need single element access i.e. no traversal.
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