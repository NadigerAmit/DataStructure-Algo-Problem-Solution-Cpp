/*
.....
.....
This problem was asked by Jane Street.

Given an arithmetic expression in Reverse Polish Notation, write a program to evaluate it.

The expression is given as a list of numbers and operands. For example: [5, 3, '+'] should return 5 + 3 = 8.

For example, [15, 7, 1, 1, '+', '-', '/', 3, '*', 2, 1, 1, '+', '+', '-'] should return 5, since it is equivalent to ((15 / (7 - (1 + 1))) * 3) - (2 + (1 + 1)) = 5.

You can assume the given expression is always valid.
*/

#include<stdio.h>
#include<iostream>
#include<list>
#include<stack>
#include<string>

using namespace std;
stack<string> S;

bool isNum(string s) {
	if(s.length()>1) return true;
	if(s =="+" || s =="-" || s =="/" || s == "*" || s == "%") {
		return false;
	}
	return true;
}

int doOperation(char c , int op1,int op2) {
	switch(c) {
		case '+':
		    return op1+op2;
		case '%':
		    return op1%op2;
		case '-':
		    return op1-op2;
		case '*':
		    return op1*op2;
		case '/':
		    return op1/op2;
		default:
		    break;
	}
	return -1111; // Magic num ;
}
int ReversePolishNotation(list<string> ls) {
	stack<int> intStack;
	for(auto i:ls) {
		if(isNum(i)) {
			intStack.push(stoi(i));
		}
		else {
			if(intStack.empty() == true) {
				cout<<"\nInValid expression"<<endl;
			}
			int op1 = intStack.top();
			intStack.pop();
			if(intStack.empty() == true) {
				cout<<"\nInValid expression"<<endl;
			}
			int op2 = intStack.top();
			intStack.pop();
			int result = doOperation(i[0] , op2,op1);
			intStack.push(result);
		}
	}
	if(intStack.size() > 1 || intStack.empty() == true) {
		cout<<"\nInValid expression"<<endl;
		return -1111;
	}
	return intStack.top();
}

int main() {
	list<string> L = {"15","7", "1", "1", "+", "-", "/", "3", "*", "2", "1", "1", "+", "+", "-"};
//	list<string> L = {"5","3","+","1","-"};
	//list<char> L = {'15','7', '1', '1', '+', '-', '/', '3', '*', '2', '1', '1', '+', '+', '-'};
	int result = ReversePolishNotation(L);
	cout<<"Result = " << result;
	return 0;
}