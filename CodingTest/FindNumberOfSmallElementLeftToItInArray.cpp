/*
This problem was asked by Google.

Given an array of integers, return a new array where each element in the new array is the number of smaller elements to the right of that element in the original input array.

For example, given the array [3, 4, 9, 6, 1], return [1, 1, 2, 1, 0], since:

There is 1 smaller element to the right of 3
There is 1 smaller element to the right of 4
There are 2 smaller elements to the right of 9
There is 1 smaller element to the right of 6
There are no smaller elements to the right of 1
*/

// In below solution , the earlier processed values are re-used .
// Find the next smaller element and then add 1 to its corresponding count in new array.
// Worst case when the elements are sorted in the Ascending order , bigO(n) = n*n
// Best case when the elements are sorted in the descending order , bigO(n) = n

#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;
#define SIZE_OFARRAY 5

void printArray(int* array,int size) {
	if(array == nullptr) return ; 
	for(int i = 0;i<size;i++) {
		printf("\n%d",array[i]);
	}
}

int* ArrayWithNumberOfSmallerNumOfElementToRight(int Array[]) {
	int* newarry = new int[SIZE_OFARRAY];
	memset(newarry,0,sizeof(int)*(SIZE_OFARRAY+1));
	newarry[SIZE_OFARRAY] = 0;
	for(int i = SIZE_OFARRAY-2;i>=0;i--) {
		int j = i; // to traverse in the sub loop till end of array 
		int k = i; // Keep track of new array index 
		while(j<SIZE_OFARRAY-1){
			if(Array[i]>Array[j+1] ) {  // the current element is bigger than the next smallest element , then take that corresponding count .
				newarry[k] = newarry[j+1]+1;
				break;
			} else {
				j++;
			}
		}
	}
	return newarry;
}



int main() {
	//int array[SIZE_OFARRAY] = {3, 4, 9, 6, 1};
	int array[SIZE_OFARRAY] = {1, 10, 9, 6, 29};
	//int array[SIZE_OFARRAY] = {3, 4, 9, 6, 1};
	int* resultArray = ArrayWithNumberOfSmallerNumOfElementToRight(array);
	printArray(resultArray,SIZE_OFARRAY);

	return 0;
}

// new array[-,-,-,-,-,0]