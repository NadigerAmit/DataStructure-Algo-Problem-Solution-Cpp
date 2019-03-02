#include<stdio.h>
#include<iostream>
#include<map>
#include<string>
#include<cstring>
#include<set>
#include<unordered_set>
#include<vector>

using namespace std;

class compare
{
public:
     bool operator()(pair<string,string> p1,pair<string,string> p2) const
     {
          if(p1.first==p2.first) {
			  return p1.second<p2.second;
		  }
		  return p1.first<p2.first;
     }
};

typedef set<pair<string, string>, compare > MMap;  // need compare function with set
//typedef multiset<pair<string, string>> MMap;     // dont need compare func with multi set , it will sort 1st based on key and then sort on values.


int main() {
	MMap mmap = {make_pair("c","k"),make_pair("b","c"),make_pair("a","d"),make_pair("b","a"),make_pair("a","b"),make_pair("b","b"),make_pair("a","c"),make_pair("c","d"),make_pair("c","c")};
	//MMap mmap;
	mmap.insert(make_pair("a", "k"));
	mmap.insert(make_pair("a", "e"));
	mmap.insert(make_pair("a", "l"));
	auto it = mmap.find(make_pair("a", "k"));
	for(auto i:mmap) {
		cout<<i.first<<" "<<i.second<<endl;
	}
	return 0;
}