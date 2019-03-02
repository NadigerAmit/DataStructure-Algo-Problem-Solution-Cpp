#include<stdio.h>
#include<iostream>
#include<set>

using namespace std;
int main() {
	multiset<int> msetInt = {1,2,4,6,7,2,34,100,-1,2,5,3,4};
	multiset<string> msetString = {"OM","Shree","GaneshshayaNamah","OM","Jai Bajarang Balai"};
	for(auto mstrValue:msetInt) {
		cout<<mstrValue<<endl;
	}
	cout<<"Strings"<<endl;
	for(auto mstrValue:msetString) {
		cout<<mstrValue<<endl;
	}
	return 0;
}
/*
std::multiset is an associative container that contains a sorted set of objects of type Key. Unlike set, multiple keys with equivalent values are allowed. Sorting is done using the key comparison function Compare. Search, insertion, and removal operations have logarithmic complexity.

Everywhere the standard library uses the Compare requirements, equivalence is determined by using the equivalence relation as described on Compare. In imprecise terms, two objects a and b are considered equivalent if neither compares less than the other: !comp(a, b) && !comp(b, a).

The order of the elements that compare equivalent is the order of insertion and does not change. (since C++11)

std::multiset meets the requirements of Container, AllocatorAwareContainer, AssociativeContainer and ReversibleContainer.
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