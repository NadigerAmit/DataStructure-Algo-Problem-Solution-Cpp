#include<stdio.h>
#include<iostream>
#include<unordered_set>
#include<string>
using namespace std;
char get1stRepetingCharinString(string s) {
	unordered_set<char> charSet;
	int i =0;
	for(i=0;i<s.length();i++) {
		if(charSet.find(s.at(i))!= charSet.end()) {
			return s.at(i);
		}
		charSet.insert(s.at(i));
	}
	return 1;
}

int main() {
	string test = "amit";
	char ct = get1stRepetingCharinString(test);
	printf("1st repeated character = %c",ct);
	return 0;
}