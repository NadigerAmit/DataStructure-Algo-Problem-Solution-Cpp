#include<stdio.h>
#include<iostream>
#include<set>
#include<vector>
#include<list>
/*
Given a list of integers S and a target number k, write a function that returns a subset of S that adds up to k. If such a subset cannot be made, then return null.

Integers can appear more than once in the list. You may assume all numbers in the list are positive.

For example, given S = [12, 1, 61, 5, 9, 2] and k = 24, return [12, 9, 2, 1] since it sums up to 24.
*/
using namespace std;
vector<int> vecInt;

void printList(list<int>& result) {
	printf("\n Result list ");
	for(auto i:result) {
		cout<<i<<" ";
	}
}

bool subsetSummingToK(int index,int sum,int K,list<int>& result) {
	if(sum == K) return true;
	int size = vecInt.size();
	for(int i = index;i<size;i++) {
		if(sum+vecInt[i] <=K) {
			sum+=vecInt[i];
			result.push_back(vecInt[i]);
			if(subsetSummingToK(i+1,sum,K,result) == true) {
				return true;
			}
			sum-=vecInt[i];
			result.pop_back();
		} else  {
			// dont do anything.
		}
	}
	return false;
}
/*
bool subsetSummingToK(int index , int sum , int K,list<int>& result) {
//	static list<int> result;
	if(sum == K) {
	//	printList(result);
		return true;
	}
	for(int i = index;i<vecInt.size();i++) {
		sum += vecInt[i];
		result.push_back(vecInt[i]);
		if(sum<=K) {
			// recusrsive call to next index
			if(subsetSummingToK(i+1,sum,K,result) == true) return true;
			sum -= vecInt[i];  // bac; tracking starts here 
			result.remove(vecInt[i]);
		} else {
			//remove the recently pushed element'
			sum -= vecInt[i];
			result.remove(vecInt[i]);
		}
	}
	return false;
}
*/
list<int> getSubsetSummingToK() {
	list<int> result;
	if(subsetSummingToK(0,0,20,result) == true)
		return result;
	else {
		return result;
	}
}

/*
bool subsetSummingToK(int index ,int K, int sum) {
	printf("\n index = %d sum = %d\n",index,sum);
	static list<int> result;
	if(sum == K) {
		printList(result);
		return true;
	}
	for(int i = index;i<vecInt.size();i++) {
		printf("\n before v[%d] = %d sum = %d",i,vecInt[i],sum);
		sum += vecInt[i];
		result.push_back(vecInt[i]);
		printf("\n v[%d] = %d sum = %d",i,vecInt[i],sum);
		if(sum<=K) {
	//		printf("\n pushing %d sum = %d",vecInt[i],sum);
		    if(subsetSummingToK(i+1,K,sum)== true) {
			    return true;
		    }
			printf("\n poping %d",vecInt[i]);
		    result.remove(vecInt[i]); // back traking 
		    sum-= vecInt[i];
		} else {
			printf("\n poping %d",vecInt[i]);
			result.remove(vecInt[i]); // back traking 
		    sum-= vecInt[i];
			//return false;
		}
	}
	return false;
}
*/
int main() {
	vecInt.push_back(12);
	vecInt.push_back(1);
	vecInt.push_back(61);
	vecInt.push_back(5);
	vecInt.push_back(9);
	vecInt.push_back(2);
	//subsetSummingToK(0,0,24);
	list<int> result = getSubsetSummingToK();
	printList(result);
	return 0;
}