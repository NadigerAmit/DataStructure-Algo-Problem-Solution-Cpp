#include<stdio.h>
#include<iostream>
using namespace std;

int main() {
	int a = 0b111; // a = 7
	int b = 1'000'000; //Digit separators

// C++ 14 Prefixes
auto str = "hello"; // auto deduces string
//auto dur = 60s;      // auto deduces chrono::seconds
auto z   = 1i;
cout<< a<<endl;
cout<< str<<endl;
//cout<< dur<<endl;
cout<< z<<endl;
cout<< b<<endl;
}