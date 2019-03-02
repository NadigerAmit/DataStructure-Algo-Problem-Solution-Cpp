/*
Om Shree Ganeshaya Namah
Jai Bajrang bali

This problem was asked by Google.

Given an array of integers where every integer occurs three times except for one integer, which only occurs once, find and return the non-duplicated integer.

For example, given [6, 1, 3, 3, 3, 6, 6], return 1. Given [13, 19, 13, 13], return 19.

Do this in O(N) time and O(1) space.

*/
#include<stdio.h>
#include<unordered_map>
#include<unordered_set>
#include<iostream>
#include<map>
#include<vector>
#include<list>
using namespace std;

int getNonDuplicatedInteger(vector<int> intVec) {
	map<int,int> map2;
	for(auto i:intVec) {  // O(n) = nlogn
		map2[i]++;
	}
	unordered_map<int,int> umap;  // Insertion is O(1)
	for(auto i:map2) {
		umap.insert(make_pair(i.second,i.first));
	}
	
	return umap.begin()->second;
}

int getNonDuplicatedIntegerBetter(vector<int> intVec) {
	unordered_map<int,int> umap;  // insertion O(1)
	unordered_set<int> intSet;    // insertion O(1)
	for(auto i:intVec) {  // O(n) = n*O(1) = n
		if(umap.find(i) == umap.end()) {
			intSet.insert(i);
			umap[i]++;
		} else {
			intSet.erase(i);
		}
	}
    if(intSet.begin() != intSet.end()) {
	     return *intSet.begin();
	}
	return -1; // -1 is magic number
}

int main() {
	vector<int> intVec = {6, 1, 3, 3, 3, 6, 6,1,2,1};
	//int nonDuplicatedInt = getNonDuplicatedInteger(intVec);
	int nonDuplicatedInt = getNonDuplicatedIntegerBetter(intVec);
	cout<<"\n Non Duplicated int = " <<nonDuplicatedInt;
	return 0;
}