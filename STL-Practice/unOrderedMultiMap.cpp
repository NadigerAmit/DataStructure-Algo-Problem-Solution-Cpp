#include<stdio.h>
#include<iostream>
#include<unordered_map>
#include <algorithm>
using namespace std;
typedef unordered_multimap<string,string> stringmap;

int main() {
	stringmap myumm = {
     {"orange","FL"},
     {"strawberry","LA"},
     {"strawberry","OK"},
     {"pumpkin","NH"}
  };

  std::cout << "Entries with strawberry:";
  auto range = myumm.equal_range("strawberry");
  for_each (
    range.first,
    range.second,
    [](stringmap::value_type& x){std::cout << " " << x.second;}
  );

  printf("\n printing the range and size = \n");
   // Stores the range of key 1 
   auto it = myumm.equal_range("strawberry"); 
  for (auto itr = it.first; itr != it.second; ++itr) { 
        cout << itr->first 
             << '\t' << itr->second << '\n'; 
    } 
  return 0;
}

/*
multimap equal_range() in C++ STL:

The multimap::equal_range() is a built-in function in C++ STL which returns an iterator of pairs. The pair refers to the bounds of a range that
 includes all the elements in the container which have a key equivalent to k. 
If there are no matches with key K, the range returned is of length 0 with both iterators pointing to the first element that has a key considered to 
go after k according to the container’s internal comparison object (key_comp).

Syntax:
iterator multimap_name.equal_range(key)

Parameters: This function accepts a single mandatory parameter key which specifies the element whose range in the container is to be returned.

Return Value: The function returns an iterator of pairs (pair<iterator,iterator> ). The pair refers to the bounds of a range that includes all the elements in the container 
which have a key equivalent to k. 

The iterators in the pair define the range of items with keys equal to what you searched for in the manner [range.first, range.second).
This means that to iterate over that range, you start from range.first and advance the iterator until it reaches range.second, which means that you have just stepped off the equal range. 
Conceptually it's the same as what happens when you iterate over a range [container.begin(), container.end()).

*/