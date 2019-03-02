#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
/*
int largestNonAdjecentSum(vector<int> array) {
	int i = 0,j = 1;
	int arraySize = array.size();
	int biggestSumFrom0 = array[i];
	int biggestSumFrom1 = array[j];
	while(1) {
		if(i<arraySize) {
			// calculate sum starting from 0th location
			if(biggestSumFrom0+i+2)>(biggestSumFrom0+i+3) {
				if(biggestSumFrom0+i+2>biggestSumFrom0) {
					i=i+
				}
			}
			
		}
		if(j<arraySize) {
			// calculate sum starting from 1st location
		}
		if(i>=arraySize && j>=arraySize) break;
	}
}
*/

int biggestNonAdjSumUtility(vector<int> array,int index,int MaxSum) {
	int biggerNumEven = MaxSum;
	int biggerNumOdd = MaxSum;
	if(array.size()<=index ) {  // this is base case.
		return MaxSum;
	}
	int origionalIndex = index;
	printf("\n size = %d index = %d",array.size(),index);
	if(array.size()>origionalIndex+2) {
		biggerNumEven += array[origionalIndex+2];
		printf("\n biggerNumEven = %d",biggerNumEven);
	}
	if(array.size()>origionalIndex+3) {	
		biggerNumOdd += array[origionalIndex+3];
		printf("\n biggerNumOdd = %d",biggerNumOdd);
	}
	if(biggerNumEven>=biggerNumOdd) {
		return biggestNonAdjSumUtility(array,index+2,(biggerNumEven>=biggerNumOdd)?biggerNumEven:biggerNumOdd);
	} else {
		return biggestNonAdjSumUtility(array,index+3,(biggerNumEven>=biggerNumOdd)?biggerNumEven:biggerNumOdd);
	}		
	return 0;
}

int biggestNonAdjSum(vector<int> array) {
	int sumFrom0 = biggestNonAdjSumUtility(array,0,array[0]);
	int sumFrom1 = 0;
	sumFrom1 = biggestNonAdjSumUtility(array,1,array[1]);
	printf("\nSum from 0 =%d and sumFrom 1 = %d\n",sumFrom0,sumFrom1);
	return (sumFrom0>sumFrom1?sumFrom0:sumFrom1);
}
/*Function to return max sum such that no two elements 
 are adjacent */
int FindMaxSum(int arr[], int n) 
{ 
  int incl = arr[0]; 
  int excl = 0; 
  int excl_new; 
  int i; 
  
  for (i = 1; i < n; i++) 
  { 
     /* current max excluding i */
     excl_new = (incl > excl)? incl: excl; 
  
     /* current max including i */
     incl = excl + arr[i]; 
     excl = excl_new; 
  } 
  
   /* return max of incl and excl */
   return ((incl > excl)? incl : excl); 
} 

int main() {
	vector<int> array  = {2,4,6,2,5};
	vector<int> vecInt = {5,1,1,5,7,8,9};
	int realArray[] = {5,1,1,5,7,8,9};
	int sum = biggestNonAdjSum(vecInt);
	printf("\n Biggest sum = %d\n",sum);
	
	printf("\n FindMaxSum = %d\n",FindMaxSum(realArray,7));
	return 0;
}