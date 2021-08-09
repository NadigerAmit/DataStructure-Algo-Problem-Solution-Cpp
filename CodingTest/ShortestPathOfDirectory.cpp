/*
This problem was asked by Quora.

Given an absolute pathname that may have . or .. as part of it, return the shortest standardized path.

For example, given "/usr/bin/../bin/./scripts/../", return "/usr/bin/".
*/
#include<stdio.h>
#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include<queue>

using namespace std;

void printStringVector(vector<string> strVector) {
	cout<<endl<<"Printing StringVector "<<endl;
	for(auto i:strVector) {
		cout<<i<<endl;
	}
}


vector<string> splitToSubString(string str) {
	vector<string> stringVector;
	int strLen = str.length();
	int startPosition = 0;
	int len = 0;
	for(int i = 0;i<strLen;i++) {
		len++;
		if(str.at(i) == '/') {  // Here ignoring the "/"
			string subString = str.substr(startPosition,len-1); // len-1 since we ignore trailing '/'
			stringVector.push_back(subString);
			startPosition = i+1;
			len = 0;
		}
	}
	return stringVector;
}


string shortestDirPath(string str) {
	stack<string> stringStack;
	vector<string> stringVector = splitToSubString(str);
	for(auto i=stringVector.begin();i!=stringVector.end();i++) {
		if(i->compare("..") == 0) {
			if(!stringStack.empty()) {
				stringStack.pop();
				continue;
			}
		} else if(i->compare(".") == 0) {
			// dont do anything since it is just .;
			continue;
		}
		stringStack.push(*i);
	}
	
	stack<string> finalStack;  // reversing the stack with another stack , other wise o/p will be in reverse order.
	while(!stringStack.empty()) {
		finalStack.push(stringStack.top());
		stringStack.pop();
	}
	
	string resultString;  // creating the final string .
	while(!finalStack.empty()) {
		resultString +=finalStack.top();
		resultString+="/";  // append the '/' at the end of each string 
		finalStack.pop();
	}
	
	return resultString;
}


int main() {
	string str = "/usr/bin/../bin/./scripts/../";
	cout<<"Result string  = " <<shortestDirPath(str);
	return 0;
}