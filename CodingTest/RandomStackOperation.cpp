#include<stdio.h>
#include<iostream>
#include<vector>
#include<stack>
#include<string>


/*
input : ops = ["5","2","C","D"]:
o/P : 30
"5" add to record [5]
"2" add to record [5,2]
"C" means -> Invalidate and remove the prvious score record becomes [2]
"D" meams -> double and add the doubled result to record i.e 5*2 = 10 , [5,10] 
"+" means  means add all the elements 

*/

using namespace std;

int makeOperation(string* str,int size) {
	if(str == nullptr) return -1;
	stack<int> intStack;
	cout<<endl<<"makeOperation"<<endl;
	for(auto i = 0;i<size;i++) {
		cout<<endl<<"i = "<<i<<endl;
		if(str[i].compare("C")== 0) {
			cout<<endl<<"C encounterd "<<i<<endl;
			if(!intStack.empty()) {
				intStack.pop();		}
			continue;
		}
		if(str[i].compare("D") == 0) {
			cout<<endl<<"D encounterd "<<i<<endl;
			int value = intStack.top();
			intStack.push(value*2);
			continue;
		}
		if(str[i].compare("+") == 0) {
			cout<<endl<<"+ encounterd "<<i<<endl;
			int sum = 0;
			while(!intStack.empty()) {
				sum += intStack.top();
				intStack.pop();
			}
			return sum;
		}
		cout<<endl<<"Normal number encounterd "<<i<<endl;
		intStack.push(stoi(str[i]));
	}
	
	return -101;
}

int main() {

vector<string> stringVec = {"5","3","2","C","D","+"};

	int result = makeOperation(stringVec.data(),stringVec.size());
	cout<<"Result = " <<result<<endl;
}
