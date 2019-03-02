#include<stdio.h>
#include<iostream>
#include<map>
#include<string>
using namespace std;
int main() {
	map<int,string> students {{1,"Om"},{2,"Shree"},{100,"GaneshayaNamah"},{4,"Jai"},{5,"BajrangBali"}};
	map<int,string>::iterator itr = students.begin();
	//students.insert(make_pair(6,"OmShivohum"));
	students.insert(make_pair(6,"OmNamahShivaya"));
	
	try{
		for(auto itr1 = students.begin();itr1!=students.end();itr1++) {
			cout<<itr1->first <<"=>" <<itr1->second;
			cout<<endl;
		}
	}catch(exception e) {
		cout<<"Exception is caught";
	}
	return 0;
}

/*
std::map Internally store elements in a balanced BST. Therefore, elements will be stored in sorted order of keys.

Here are few important tips to remember about Map & Multimap
The multimap stores pairs of (key, value) where both key and value can appear several times
The map < key, set < value > > will only store each value once for a specific key. To do that, it will have to be able to compare the values, not just the keys
A std::map is an associative container, that allows you to have a unique key associated with your type value
*/