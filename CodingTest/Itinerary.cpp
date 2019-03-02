

#include<stdio.h>
#include<iostream>
#include<map>
#include<unordered_map>
#include<list>
#include<string>
#include<vector>
#include<set>
//#include<priority_queue>
#include<queue>
using namespace std;
typedef multiset<pair<string,string>> mset;
typedef pair<string,string> iPair;

/*
This problem was asked by Facebook.

Given an unordered list of flights taken by someone, each represented as (origin, destination) pairs, and a starting airport, compute the person's itinerary. 
If no such itinerary exists, return null. If there are multiple possible itineraries, return the lexicographically smallest one. All flights must be used in the itinerary.

For example, given the list of flights [('SFO', 'HKO'), ('YYZ', 'SFO'), ('YUL', 'YYZ'), ('HKO', 'ORD')] and starting airport 'YUL', you should return the list ['YUL', 'YYZ', 'SFO', 'HKO', 'ORD'].

Given the list of flights [('SFO', 'COM'), ('COM', 'YYZ')] and starting airport 'COM', you should return null.

Given the list of flights [('A', 'B'), ('A', 'C'), ('B', 'C'), ('C', 'A')] and starting airport 'A', 
you should return the list ['A', 'B', 'C', 'A', 'C'] even though ['A', 'C', 'A', 'B', 'C'] is also a valid itinerary. However, the first one is lexicographically smaller.
*/

list<string> prepareList(pair<string,string> srcPair, mset srcMap) {  // start of the Itinerary is given and find fomplete path .
	multimap<string,string> mmap;
	for(auto i:srcMap) {
		mmap.insert(i);
	}
	list<string> iternaryList;
	auto itr = mmap.find(srcPair.first);
	iternaryList.push_back(itr->first);
	while(itr != mmap.end()) {
		iternaryList.push_back(itr->second);
		cout<<"Erasing "<<itr->first <<"-->"<<itr->second<<endl;
		mmap.erase(itr);
		itr = mmap.find(itr->second);
	}
	return iternaryList;
}

/*
Find Itinerary from a given list of tickets:
Input:
"Chennai" -> "Banglore"
"Bombay" -> "Delhi"
"Goa"    -> "Chennai"
"Delhi"  -> "Goa"

Output: 
Bombay->Delhi, Delhi->Goa, Goa->Chennai, Chennai->Banglore,

Complexity of below operation is O(n) = (n)log(n).
*/
list<string> getIteraryFormTickets(mset srcMap) {  // This is to find the start of Itinerary assuming no cycles or loops 
	// map<string,string> srcMap // src ,dest
	unordered_multimap<string,string> destMap;// dest,src
	pair<string,string> src;
	for(auto i:srcMap) {
		destMap.insert(make_pair(i.second,i.first)); // Prepared dest map
	}
//	for(auto j:destMap) cout<<j.first<<"<--"<<j.second<<endl;
	// Find the source 
	for(auto i:srcMap) {
		if(destMap.find(i.first) == destMap.end()) {
		    src = i;
		    cout<< "src = "<<src.first<<endl;
		    break;
		}
	}
	return prepareList(src,srcMap);
}
void printfList(list<string> lst) {
	int count = 1;
	int size = lst.size();
	if(size == 0) {
		printf("\n there is no continues path ");
	}
	printf("\n ");
	for(auto i:lst){
		count++;
		cout<<i;
		if(count<=size)
			cout<<"-->";
	}
}

int main() {
	mset srcMap = {make_pair("Goa","Darjeeling"),make_pair("Hubli","Bombay"),make_pair("Chennai","Banglore"),make_pair("Bombay","Delhi"),make_pair("Bombay","Goa"),make_pair("Mangalore","Hubli"),make_pair("Goa","Chennai"),make_pair("Delhi","Goa"),make_pair("Banglore","Mangalore")};
	//map<string,string> srcMap = {make_pair("Chennai","Banglore"),make_pair("Bombay","Delhi"),make_pair("Goa","Chennai"),make_pair("Delhi","Goa")};
	//list<string> iternary = getIteraryFormTickets(srcMap);
	printf("\n Printing the MMap\n");
	for(auto i:srcMap) {
		cout<<i.first<<" "<<i.second<<endl;
	}
	
	list<string> iternary = prepareList(make_pair("Bombay","Delhi"),srcMap);
	printf("iternary.size() = %d srcMap.size() = %d",iternary.size(),srcMap.size());
	/*
	if(iternary.size()<srcMap.size()) {
		printf("\n No continues iternery ");
		return 0;
	}
	*/
	printfList(iternary);
	return 0;
}
	