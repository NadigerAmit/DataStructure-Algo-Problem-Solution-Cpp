/*
This problem was asked by Microsoft.
A number is considered perfect if its digits sum up to exactly 10.
Given a positive integer n, return the n-th perfect number.
For example, given 1, you should return 19. Given 2, you should return 28.
*/

#include<stdio.h>
#include<iostream>
#include<string>
#include <sstream>
//#include<stringstream>

using namespace std;
int getSumOfInputDigits(int input){
	stringstream ss;
	ss<<input;
	string str = ss.str();
	int sum = 0;
	int i=0;
	while(i<str.length()) {
		char buff = str[i];
		sum+=atoi(&buff);
		i++;
	}
	printf("Sum = %d",sum);
	return sum;
}
int getPerfectNumOfSum(int input,int target) {
	int sumofInputDigits = getSumOfInputDigits(input);
	if(sumofInputDigits>target) return -1;
	if(sumofInputDigits == target) return input;
	int numToBeAdded = target-sumofInputDigits;
	int mul = 10;
	while(numToBeAdded>mul)  {
		mul *=10;
	}
	int perfectNum = input*mul+numToBeAdded;
//	printf("\nPerfect Num = %d",perfectNum);
	return perfectNum;
}

int main() {
	int num = 123;
	int perfectNum = getPerfectNumOfSum(num,10);
	printf("\n Perfect num = %d\n",perfectNum);
	return 0;
}