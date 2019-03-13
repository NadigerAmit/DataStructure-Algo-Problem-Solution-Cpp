#include<stdio.h>
#include<iostream>
#include<unordered_set>
#include<string>
using namespace std;
// With Map 
char get1stRepetingCharinString(string s) {
	unordered_set<char> charSet;
	int i =0;
	for(i=0;i<s.length();i++) {
		if(charSet.find(s.at(i))!= charSet.end()) {
			return s.at(i);
		}
		charSet.insert(s.at(i));
	}
	return 0;
}

// Without Map
char get1stRecurringChar(string str) {
	for(int i = 1;i<str.length();i++) {
		if(str[i] == str[i-1]) {
//			cout<<"\nRepeated char = "<<str[i]; 
			return str[i];
		}
	}
	cout<<"Retruning no repeatation";
	return 0;
}

int main() {
	string test = "amit";
	char ct = get1stRepetingCharinString(test);
	printf("1st repeated character = %c",ct);
	return 0;
}
