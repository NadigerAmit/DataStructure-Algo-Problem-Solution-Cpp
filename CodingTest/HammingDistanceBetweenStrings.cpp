#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
/*
You are given two strings of equal length, you have to find the Hamming Distance between these string.
Where the Hamming distance between two strings of equal length is the number of positions at which the corresponding character are different.

Input : str1[] = "geeksforgeeks", str2[] = "geeksandgeeks"
Output : 3
Explanation : The corresponding character mismatch are highlighted.
"geeksforgeeks" and "geeksandgeeks"

Input : str1[] = "1011101", str2[] = "1001001"
Output : 2
Explanation : The corresponding character mismatch are highlighted.
"1011101" and "1001001"

*/

int hammingDistance(string str1, string str2) {
	int i = 0;
	int misMatchCount = 0;
	while(str1[i] != '\0') {
		if(str1[i]!=str2[i]) {
			misMatchCount++;
		}
		i++;
	}
	if(str2[i]!='\0') {
		misMatchCount+=str2.length()-i;
	}
	return misMatchCount;
}

int main() {
	string str1 = "geekspractice"; 
    string str2 = "nerdspractise";
	printf("Distance between %s and %s is %d",str1.c_str(),str2.c_str(),hammingDistance(str1,str2));
	return 0;
}