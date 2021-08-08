#include <algorithm>
#include <list>
#include <vector>
#include <iostream>
#include <numeric>
#include <random>
#include <functional>
 
 /*
	 **********************
	 std::reference_wrapper is a class template that wraps a reference in a copyable, assignable object. 
	 It is frequently used as a mechanism to store references inside standard containers (like std::vector) which cannot normally hold references.

	Specifically, std::reference_wrapper is a CopyConstructible and CopyAssignable wrapper around a reference to object or reference to function of type T. 
	Instances of std::reference_wrapper are objects (they can be copied or stored in containers) but they are implicitly convertible to T&, 
	so that they can be used as arguments with the functions that take the underlying type by reference.

	If the stored reference is Callable, std::reference_wrapper is callable with the same arguments.

	Helper functions std::ref and std::cref are often used to generate std::reference_wrapper objects.

	std::reference_wrapper is also used to pass objects by reference to std::bind, the constructor of std::thread, or the helper functions std::make_pair and std::make_tuple.

	std::reference_wrapper is guaranteed to be TriviallyCopyable.

	(since C++17)
	T may be an incomplete type.

(since C++20)

*************************************
 Below example :
     Demonstrates the use of reference_wrapper as a container of references, which makes it possible to access the same container using multiple indexes
 */
int main()
{
    std::list<int> l(10);
 
    std::iota(l.begin(), l.end(), -4);
    std::vector<std::reference_wrapper<int>> v(l.begin(), l.end());
 
    // can't use shuffle on a list (requires random access), but can use it on a vector
    std::shuffle(v.begin(), v.end(), std::mt19937{std::random_device{}()});
 
    std::cout << "Contents of the list: ";
    for (int n : l){ 
        std::cout << n << ' ';
    }
 
    std::cout << "\nContents of the list, as seen through a shuffled vector: ";
    for (int i : v){
        std::cout << i << ' ';
    }
 
    std::cout << "\n\nDoubling the values in the initial list...\n\n";
    for (int& i : l) {
        i *= 2;
    }
 
    std::cout << "Contents of the list, as seen through a shuffled vector: ";
    for (int i : v){
       std::cout << i << ' ';
    }
}
/*
Contents of the list: -4 -3 -2 -1 0 1 2 3 4 5
Contents of the list, as seen through a shuffled vector: 5 0 -2 3 1 -3 2 -4 -1 4

Doubling the values in the initial list...

Contents of the list, as seen through a shuffled vector: 10 0 -4 6 2 -6 4 -8 -2 8
*/