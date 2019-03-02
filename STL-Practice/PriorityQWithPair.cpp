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
vector<iPair> pairVect;
set<iPair> pairSet;
