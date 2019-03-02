#include<stdio.h>
#include<iostream>
#include<string>
#include<stdlib.h>
#include<cstring>
/*
Problem :Implement run-length encoding and decoding.
Run-length encoding is a fast and simple method of encoding strings.
 The basic idea is to represent repeated successive characters as a single count and character. 
 For example, the string "AAAABBBCCDAA" would be encoded as "4A3B2C1D2A".
*/
using namespace std;
string EncodeToRunLengthEncoding(string& str) {
	cout<<"input String = "<<str;
	int i = 0;
	string result;
	char c = str[0];
	int count = 0;
	char buff[100]; 
	while(str[i]!='\0') {
		if(str[i] == c) {
			count++;
		} else {
			result.append(itoa(count,buff,10));
			result.append(&c,1);
			c = str[i];
			count = 1;
		}
		i++;
	}
	if(count >0) {
		result.append(itoa(count,buff,10)); // int count ,char buffer , 10 is base 10,
		result.append(&c,1);
	}
	return result;
}
string DecodeRunLengthEncoding(string& str) {
	int i = 0;
	string result;
	int count = 0;
	while(str[i]!='\0') {
		count = atoi(str[++i].c_str());
		result.append(count,str[i]);  // count number of ties , str[i] character will be copied.
        i++;
	}
	return result;
}

int main() {
	string str = "AAAABBBCCDAA";
	string result =  EncodeToRunLengthEncoding(str);
	cout<<"Encoded string = "<<result<<endl;
	cout<<"Decoded string = "<<DecodeRunLengthEncoding(result);
	return 0;
}