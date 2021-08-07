/*

Suppose we have some input data describing a graph of relationships between parents and children over multiple generations. The data is formatted as a list of (parent, child) pairs, where each individual is assigned a unique positive integer identifier.

For example, in this diagram, 3 is a child of 1 and 2, and 5 is a child of 4:

1   2    4   15
 \ /   / | \ /
  3   5  8  9
   \ / \     \
    6   7    11


Sample input/output (pseudodata):

parentChildPairs = [
    (1, 3), (2, 3), (3, 6), (5, 6), (15, 9),
    (5, 7), (4, 5), (4, 8), (4, 9), (9, 11)
]


Write a function that takes this data as input and returns two collections: one containing all individuals with zero known parents, and one containing all individuals with exactly one known parent.


Output may be in any order:

findNodesWithZeroAndOneParents(parentChildPairs) => [
  [1, 2, 4, 15],       // Individuals with zero parents
  [5, 7, 8, 11]        // Individuals with exactly one parent
]

Complexity Analysis variables:

n: number of pairs in the input


*/


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include<set>
#include<utility>
using namespace std ;

pair<set<int>,set<int>> ZeroOneParent(vector<pair<int, int>> inputData) {
	multiset<int> parentSet;
	multiset<int> childernSet;
	
	set<int> zeroParentChildernSet;
	set<int> oneParentChildernSet;
	for(auto i:inputData) {
		parentSet.insert(i.first);
		childernSet.insert(i.second);
	}
	
       for(auto i:inputData) {
		if(childernSet.find(i.first) == childernSet.end()){
			zeroParentChildernSet.insert(i.first);
		}
	}
	
	for(auto i:inputData) {
		if(childernSet.find(i.second) != childernSet.end()) {
			if(oneParentChildernSet.find(i.second) != oneParentChildernSet.end()) {
				oneParentChildernSet.erase(i.second);
			} else {
				oneParentChildernSet.insert(i.second);
			}
		}
	}
	return make_pair(zeroParentChildernSet,oneParentChildernSet);
}


int main() {
  vector<pair<int, int>> parent_child_pairs = {
    make_pair(1, 3),
    make_pair(2, 3),
    make_pair(3, 6),
    make_pair(5, 6),
    make_pair(15, 9),
    make_pair(5, 7),
    make_pair(4, 5),
    make_pair(4, 8),
    make_pair(4, 9),
    make_pair(9, 11)
    
  };

  pair<set<int>,set<int>> returnValue = ZeroOneParent(parent_child_pairs);
  cout<<"Zero Parent"<<endl;
  for(auto i: returnValue.first) {
	  cout<<i<<endl;
  }
  
  cout<<"One Parent"<<endl;
  for(auto i: returnValue.second) {
	  cout<<i<<endl;
  }
  
  return 0;
}
