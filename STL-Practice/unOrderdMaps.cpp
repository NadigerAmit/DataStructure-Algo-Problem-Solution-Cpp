#include<stdio.h>
#include<iostream>
#include <unordered_map> 
#include<string>
#include <sstream> 
using namespace std;

// Prints frequencies of individual words in str 
void printFrequencies(const string &str) 
{ 
    // declaring map of <string, int> type, each word 
    // is mapped to its frequency 
    unordered_map<string, int> wordFreq; 
  
    // breaking input into word using string stream 
    stringstream ss(str);  // Used for breaking words 
    string word; // To store individual words 
    while (ss >> word) 
        wordFreq[word]++; 
  
    // now iterating over word, freq pair and printing 
    // them in <, > format 
    unordered_map<string, int>:: iterator p; 
	cout<<"\n Hash map size = "<<wordFreq.max_size() <<endl;
    for (p = wordFreq.begin(); p != wordFreq.end(); p++) {
        cout << "(" << p->first << ", " << p->second << ")";
		cout<<"=>BucketNum = "<<wordFreq.bucket(p->first) << endl;
	}
	
	std::cout << "mymap's buckets contain:\n";
  for ( unsigned i = 0; i < wordFreq.bucket_count(); ++i) {
    cout << "bucket #" << i << " contains:";
    for ( auto local_it = wordFreq.begin(i); local_it!= wordFreq.end(i); ++local_it )
      std::cout << " " << local_it->first << ":" << local_it->second;
    std::cout << std::endl;
  }
	
	cout<<"\nBucketCount = " <<wordFreq.bucket_count();
}

int main() {
	string str = "geeks for geeks geeks quiz practice qa for"; 
    printFrequencies(str); 
    return 0; 
}

/*

std::unordered_map store elements using hash table. Therefore, elements will not be stored in any sorted order. They will be stored in arbitrary order .

Advantages of BST over Hash Table
Hash Table supports following operations in Θ(1) time.
1) Search
2) Insert
3) Delete

The time complexity of above operations in a self-balancing Binary Search Tree (BST) (like Red-Black Tree, AVL Tree, Splay Tree, etc) is O(Logn).
So Hash Table seems to beating BST in all common operations. When should we prefer BST over Hash Tables, what are advantages. Following are some important points in favor of BSTs.

We can get all keys in sorted order by just doing Inorder Traversal of BST. This is not a natural operation in Hash Tables and requires extra efforts.
Doing order statistics, finding closest lower and greater elements, doing range queries are easy to do with BSTs. Like sorting, these operations are not a natural operation with Hash Tables.
BSTs are easy to implement compared to hashing, we can easily implement our own customized BST. To implement Hashing, we generally rely on libraries provided by programming languages.
With Self-Balancing BSTs, all operations are guaranteed to work in O(Logn) time. But with Hashing, Θ(1) is average time and some particular operations may be costly, 
especially when table resizing happens.

Unordered maps implement the direct access operator (operator[]) which allows for direct access of the mapped value using its key value as argument.

reserve() -->  Request a capacity change (public member function).
bucket() ==> Returns the bucket number where the element with key k is located.

A bucket is a slot in the container's internal hash table to which elements are assigned based on the hash value of their key. Buckets are numbered from 0 to (bucket_count-1).

Individual elements in a bucket can be accessed by means of the range iterators returned by unordered_map::begin and unordered_map::end.
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
