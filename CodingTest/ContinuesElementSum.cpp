#include<stdio.h>
#include<iostream>
#include<list>
#include<vector>

using namespace std;

/*
This problem was asked by Lyft.

Given a list of integers and a number K, return which contiguous elements of the list sum to K.

For example, if the list is [1, 2, 3, 4, 5] and K is 9, then it should return [2, 3, 4].
*/

list<int> ListWithContinuousElementSum(list<int> lst, int K) {
	list<int> sumList;
	int sum = 0;

	if(sum == K) return sumList;
	auto a = lst.begin();
    if(*a == K) {
		sumList.push_back(*a);
		return sumList;
	}
	for(auto i = lst.begin();i!=lst.end();i++) {
		for(auto j = i;j!=lst.end();j++) {
			sum+=*j;
			sumList.push_back(*j);
			if(sum == K) {
				return sumList;
			} else if(sum > K) {
				break;
			} else {
				// just continue
			}
		}
		sum = 0;
		sumList.clear();
	}
	sumList.clear();
	return sumList;
}

int sum = 0;
list<int> lst;
bool subSetSum(vector<int> vec,int index,int K ) {
	printf("\n sum = %d i = %d",sum,index);
	if(sum == K) return true;
	for(auto i=index;i<vec.size();i++) {
		sum +=vec[i];
		lst.push_back(vec[i]);
		if(sum == K) return true;
		if(sum<K) {
			 if(subSetSum(vec,i+1,K) == true) return true;
			 lst.pop_back();
			 sum-=vec[i];
		} else {
			// Backtrack
			lst.pop_back();
			sum-=vec[i];
		}
	}
	return false;
}

int main() {
	list<int> lst1 = {1, 2, 3, 4, 5};
	vector<int> vec = {12, 1, 61, 5, 9, 2};
	list<int> sumList = ListWithContinuousElementSum(lst1,1);
	cout<<"LIst Sum = \n";
	for(auto i:sumList) {
		cout<<i<<endl;
	}
	printf("\n *********************************\n");
	if(subSetSum(vec,0,10) == true) {
		printf("\n Soluntion exists \n");
		for(auto i:lst) {
			cout<<i<<endl;
		}
	} else {
		printf("Solution dont exists ");
	}
	
	return 0;
}