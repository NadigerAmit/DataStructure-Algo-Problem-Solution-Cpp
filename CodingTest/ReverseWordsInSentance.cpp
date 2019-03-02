/*
Write a C program to reverse the words in a sentence in place. 
Ex; I am a good boy
O/P : boy good a am I
*/

#include<stdio.h>
#include<iostream>
#include<sstream>
using namespace std;
string reverseStringinSentance(string& str) {
	cout<<str<<endl;
	stringstream ss(str);
	string world;
	int count = 0;
	string op;
	while(ss>>world) {
		
		count++;
	//	if(count == 1) continue;
		ss<<world;
		op =world+" "+op;
	//	ss<<" ";
		cout<<world<<endl;
	}
    str = op;
	cout<< "\n O/p string = "<<str<<endl;
	return op;
}


int main() {
	string str("Amit is good boy ");
//	cout<<"Enter the sentance\n";
//	cin>>str;
	cout<<"\n Intputted strting = "<<str<<endl;
	reverseStringinSentance(str);
	return 0;
}