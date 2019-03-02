/*
An sorted array of integers was rotated an unknown number of times.

Given such an array, find the index of the element in the array in faster than linear time. If the element doesn't exist in the array, return null.

For example, given the array [13, 18, 25, 2, 8, 10] and the element 8, return 4 (the index of 8 in the array).
*/
#include<stdio.h>
#include<iostream>

int doBinarySearch(int array[],int key,int start,int end) {
	if(start > end) return -1;
	int mid = (start+end)/2;
	if(array[mid] == key) return mid;
	if(array[mid]>key) return doBinarySearch(array,key,start,mid-1);
	return doBinarySearch(array,key,mid+1,end);
}

int findPivotIndex(int array[],int start,int end) {
	if(start>end) return -1;
	if(start == end) return start;
	int mid = (start+end)/2;
	if(array[mid]>array[mid+1]) return mid;
	if(array[mid-1]>array[mid]) return mid-1;
	if(array[mid]>array[end]) return findPivotIndex(array,mid+1,end);
	return findPivotIndex(array,start,mid-1);
}

int findElementInRotatedSortedArray(int array[],int key,int start,int end) {
	int pivot = findPivotIndex(array,start,end);
	if(array[pivot] == key) return pivot;
	if(pivot == -1 || pivot == 0 || pivot == end) return doBinarySearch(array,key,start,end);
	if(key<array[0]) return doBinarySearch(array,key,pivot,end);
	return doBinarySearch(array,key,start,pivot);
}

int findPivot(int array[],int key,int start,int end) {
	if(start>end) return -1;
	if(start==end) return start;
	int mid = (start+end)/2;
	if(array[mid]>array[mid+1]) return mid;
	if(array[mid-1]>array[mid]) return mid-1;
	if(array[mid]>array[end]) return findPivot(array,mid+1,end);
	return  findPivot(array,start,mid-1);
}

int main() {
	//int array[] = {13, 18, 25, 2, 8, 10};
	//int array[] = { 2, 8, 10,13, 18, 25};
	//int array[] = {15, 18, 2, 3, 6, 12,13}; 
	int array[] = {2, 3, 6, 12,13,15,18};
//	int array[] = {1, 2, 3, 4, 5, 6,7,8,9,10};
//	int array[] = {8,9,10,1, 2, 3, 4, 5, 6,7};
	int start = 0;
	int end = sizeof(array)/sizeof(array[0]);
	int index = doBinarySearch(array,13,start,end-1);
	int pivotIndex = findPivotIndex(array,start,end-1);
	int keyInedx =  findElementInRotatedSortedArray(array,12,start,end-1);
	printf("\n pivotIndex Index  point  = %d \n",pivotIndex);
	printf("\n keyInedx point  = %d \n",keyInedx);
	return 0;
}