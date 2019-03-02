#include<stdio.h>
#include<iostream>
#include<set>
#include<list>

using namespace std;

multiset<int> sortedSquare(list<int> inputLst) {
	multiset<int> uset;
	for(auto i:inputLst) {
		uset.insert(i*i);
	}
	return uset;
}
int main() {
	list<int> lst = {-9, -2, 0, 2, 3};
	multiset<int> uset = sortedSquare(lst);
	for(auto i:uset) {
		cout<<i<<endl;
	}
	return 0;
}