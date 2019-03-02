#include<stdio.h>
#include<iostream>
#include <unordered_set>

int main ()
{
  std::unordered_multiset<std::string> myums =
    {"cow","pig","chicken","pig","pig","cow"};

  for (auto& x: {"cow","sheep","pig"}) {
    std::cout << x << ": " << myums.count(x) << std::endl;
  }
  
  std::cout << "size = " << myums.size() << std::endl;
  std::cout << "bucket_count = " << myums.bucket_count() << std::endl;
 printf("\ncalculated load factor size/bucket_count = %f\n",float(myums.size())/float(myums.bucket_count()));
  std::cout << "load_factor = " << myums.load_factor() << std::endl;
  std::cout << "max_load_factor = " << myums.max_load_factor() << std::endl;

  return 0;
}

/*
Unordered Multiset
Unordered multisets are containers that store elements in no particular order, allowing fast retrieval of individual elements based on their value,
 much like unordered_set containers, but allowing different elements to have equivalent values.

In an unordered_multiset, the value of an element is at the same time its key, used to identify it.
 Keys are immutable, therefore, the elements in an unordered_multiset cannot be modified once in the container - they can be inserted and removed, though.

Internally, the elements in the unordered_multiset are not sorted in any particular, but organized into buckets depending on their hash values to allow for fast access
 to individual elements directly by their values (with a constant average time complexity on average).

Elements with equivalent values are grouped together in the same bucket and in such a way that an iterator (see equal_range) can iterate through all of them.

Iterators in the container are at least forward iterators.
Notice that this container is not defined in its own header, but shares header <unordered_set> with unordered_set.

float load_factor() const noexcept;
Return load factor
Returns the current load factor in the unordered_multiset container.

The load factor is the ratio between the number of elements in the container (its size) and the number of buckets (bucket_count):

load_factor = size / bucket_count 

The load factor influences the probability of collision in the hash table (i.e., the probability of two elements being located in the same bucket). The container automatically increases 
the number of buckets to keep the load factor below a specific threshold (its max_load_factor), causing a rehash each time an expansion is needed.

To retrieve or change this threshold, use member function max_load_factor.

*/
