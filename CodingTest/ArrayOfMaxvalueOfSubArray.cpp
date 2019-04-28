/*
This problem was asked by Google.

Given an array of integers and a number k, where 1 <= k <= length of the array, compute the maximum values of each subarray of length k.

For example, given array = [10, 5, 2, 7, 8, 7] and k = 3, we should get: [10, 7, 8, 8], since:

10 = max(10, 5, 2)
7 = max(5, 2, 7)
8 = max(2, 7, 8)
8 = max(7, 8, 7)
Do this in O(n) time and O(k) space. You can modify the input array in-place and you do not need to store the results.
You can simply print them out as you compute them.

*/

#include<stdio.h>
#include<iostream>
#include<vector>
#include<set>

using namespace std;

void printMaxOfSubArray(int array[],int size ,int k) {
	set<int> intSet ;
	bool countKreached = false;
	k = k-1; // since 3 elemets should be considerd and i is considered from 0.
	for(int i = 0;i<size;i++) {
		intSet.insert(array[i]);
		if(i == k) countKreached = true; // waiting for 1st k elements of array to be inserted in to set.
		if(countKreached == true) {
			printf("%d\n",*(intSet.rbegin())); // print the max of 3 elemnts 
			intSet.erase(array[i-k]); // erase the elemnts of array 
		}
	}
}

int main() {
	int a[] = {10, 5, 2, 7, 8, 7};
	int k = 3;
	printMaxOfSubArray(a,sizeof(a)/sizeof(a[0]),k);
	return 0;
}
