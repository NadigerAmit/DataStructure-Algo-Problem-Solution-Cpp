#include<stdio.h>
#include<iostream>
#include<map>
#include<vector>
#include <utility>

using namespace std;

map<int,int> mergeInterval(vector<pair<int,int>> intervalVec) {
	vector<pair<int,int>> resultVec;
	map<int,int> intervalMap;
	// insert in to map 
	for(auto i:intervalVec) {
		intervalMap[i.first] = i.second;
	}
	auto it = intervalMap.begin();
	it++;
	
	for(auto i = intervalMap.begin();it != intervalMap.begin();i++,it++) {
		if(it == intervalMap.end()) break;
		if(i->second >it->first ) {
			// merge here 
			i->second = it->second;
			intervalMap.erase(it);
		}
	}
	return intervalMap;
}

int main() {
	
	// INPUT in verctor of pairs 
	vector<pair<int,int>> intervalVec = {make_pair(1,3),make_pair(2,6),make_pair(8,10),make_pair(15,18)};
	map<int,int> intervalMap = mergeInterval(intervalVec);
	for(auto i:intervalMap) {
		cout<<i.first <<"----" <<i.second<<endl;
	}
}
