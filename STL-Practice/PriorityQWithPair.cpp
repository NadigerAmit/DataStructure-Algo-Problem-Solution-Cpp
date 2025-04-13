/*
https://en.cppreference.com/w/cpp/container/priority_queue

The priority queue is a container adaptor that provides constant time lookup of the largest (by default) element, at the expense of logarithmic insertion and extraction.

A user-provided Compare can be supplied to change the ordering, e.g. using std::greater<T> would cause the smallest element to appear as the top().

Working with a priority_queue is similar to managing a heap in some random access container, with the benefit of not being able to accidentally invalidate the heap.

*/
#include<stdio.h>
#include<iostream>
#include<queue>
#include<vector>

using namespace std;
typedef pair<int ,int> iPair; // weight and node

int main() {
	priority_queue<iPair,vector<iPair>,greater<iPair>> pq;

	pq.push(make_pair(13,4));
	pq.push(make_pair(5,4));
	pq.push(make_pair(8,4));
	pq.push(make_pair(8,4));
	pq.push(make_pair(5,8));
	pq.push(make_pair(5,9));
	
	while(!pq.empty()) {
		iPair ins = pq.top();
		pq.pop();
		cout<<ins.first <<"------"<<ins.second<<endl;
	}
	return 0;
}
/*
5------4
5------8
5------9
8------4
8------4
13------4
*/
