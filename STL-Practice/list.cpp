#include<stdio.h>
#include<iostream>
#include<list>  // double linked list

#include <forward_list>  // single linked list 

using namespace std;
int main() {
	list<int> lstInt = {1,32,23,33,43,1,0};
	list<int>::iterator itr;
	lstInt.reverse();
	lstInt.remove(33);
	lstInt.push_front(33);
	for(itr=lstInt.begin();itr!=lstInt.end();itr++) {
		if(*itr == 33) {
			//
			cout<<"Erasing";
			cout<<endl;
			//continue;
		}
		cout<<*itr;
		cout<<endl;
	}
  forward_list<int> mylist = {77, 2, 16};
  mylist.push_front (19);
  mylist.push_front (34);
  cout<<"\n************iterating foreward_list*************\n";
  for (auto x: mylist) std::cout << ' ' << x;
  std::cout << '\n';
  cout<<"\n************using pop_front() of foreward_list*************\n";
  while (!mylist.empty())
  {
    std::cout << ' ' << mylist.front();
    mylist.pop_front();
  }
	
	return 0;
}

/*

Forward lists are implemented as singly-linked lists; Singly linked lists can store each of the elements they contain in different and unrelated storage locations. 
The ordering is kept by the association to each element of a link to the next element in the sequence.

The main design difference between a forward_list container and a list container is that the first keeps internally only a link to the next element, while the latter keeps two links per element: 
one pointing to the next element and one to the preceding one, allowing efficient iteration in both directions, but consuming additional storage per element and with a slight higher time overhead 
inserting and removing elements. forward_list objects are thus more efficient than list objects, although they can only be iterated forwards. 
*/