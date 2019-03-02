#include<stdio.h>
#include<iostream>
#include<map>
using namespace std;

int main() {
	multimap<int ,string> gods = {{1,"Om"},{2,"Shree"},{3,"Ganeshaya Namah"},{1,"Om"},{1,"Jai Bajarang Bali"}};
	gods.insert(make_pair(1,"Jai"));
	gods.insert(make_pair(3,"BajarangBali"));
	gods.insert(make_pair(3,"OMNamahShivaya"));
	for(auto itr:gods) {
		cout<<itr.first <<"=" <<itr.second <<endl;
	}
	
	printf("\n printing the range of values ");
	// Stores the range of key 1 
    auto it = gods.equal_range(1); 
	cout << "The multimap elements of key 1 is : \n"; 

	for (auto itr = it.first;itr!=it.second;itr++) {
	//for (auto itr = it;itr<=it.size();itr++) { 
        cout << itr->first 
             << '\t' << itr->second << '\n'; 
    } 
	return 0;
	
	
}

/*
A std::multimap is equal to a std::map, but your keys are not unique anymore. Therefore you can find a range of items instead of just find one unique item. 
Multimaps are associative containers that store elements formed by a combination of a key value and a mapped value, following a specific order, and where multiple elements can have equivalent keys.

Internally, the elements in a multimap are always sorted by its key following a specific strict weak ordering criterion indicated by its internal comparison object (of type Compare).
multimap containers are generally slower than unordered_multimap containers to access individual elements by their key, but they allow the direct iteration on subsets based on their order.

Multimaps are typically implemented as binary search trees.

multimap equal_range() in C++ STL:

The multimap::equal_range() is a built-in function in C++ STL which returns an iterator of pairs. The pair refers to the bounds of a range that
 includes all the elements in the container which have a key equivalent to k. 
If there are no matches with key K, the range returned is of length 0 with both iterators pointing to the first element that has a key considered to 
go after k according to the container’s internal comparison object (key_comp).

Syntax:
iterator multimap_name.equal_range(key)
pair<iterator,iterator> equal_range( const Key& key );

Parameters: This function accepts a single mandatory parameter key which specifies the element whose range in the container is to be returned.

Return Value: The function returns an iterator of pairs (pair<iterator,iterator> ). The pair refers to the bounds of a range that includes all the elements in the container 
which have a key equivalent to k. 

The iterators in the pair define the range of items with keys equal to what you searched for in the manner [range.first, range.second).
This means that to iterate over that range, you start from range.first and advance the iterator until it reaches range.second, which means that you have just stepped off the equal range. 
Conceptually it's the same as what happens when you iterate over a range [container.begin(), container.end()).

std::pair containing a pair of iterators defining the wanted range: the first pointing to the first element that is not less than key and the second pointing to the first element greater than key.
If there are no elements not less than key, past-the-end (see end()) iterator is returned as the first element. 
Similarly if there are no elements greater than key, past-the-end iterator is returned as the second element.

Alternatively, the first iterator may be obtained with lower_bound(), and the second with upper_bound().
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