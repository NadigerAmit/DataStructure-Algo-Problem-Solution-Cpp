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

// In below solution , the earlier processed values of each number are re-used .
// Find the next smaller element and then add 1 to its corresponding count in new array.
// Worst case when the elements are sorted in the Ascending order , bigO(n) = n*n
// Best case when the elements are sorted in the descending order , bigO(n) = n

#include<stdio.h>
#include<iostream>
#include<cstring>
#include <vector>

using namespace std;
/////////////////////////////////////////////////////////////////////////////////
// Using vector 
vector<int> countSmaller(vector<int> v) {
    vector<int> result(v.size(),0);
    int count = 0;
    result[v.size()-1] = 0;
    
    for(int i = v.size()-1; i>=0;i--) {
        result[i] = 0;
        for(int j = i; j<v.size();j++) {
            if(v[i] > v[j]) {
                result[i]++;
                cout<< result[i]<<endl;
            } 
        }
    }
    return result;
}
/////////////////////////////////////////////////////////////////////////////////
void printArray(int* array,int size) {
	if(array == nullptr) return ; 
	for(int i = 0;i<size;i++) {
		printf("\n%d",array[i]);
	}
}

int* ArrayWithNumberOfSmallerNumOfElementToRight_simple(int array[],int size) {
    //int numOfElements = sizeof(array)/sizeof(array[0]);
    int* resultArray = new int [size];
    resultArray[size-1] = 0;  // last element value = 0;
    for(int i = size-2;i>=0;i--) {  // star the i with 2nd elemnt from the last i.e size-2.
        int key = array[i];   // 2nd elemnt from lst from begining.
        for(int j = i+1;j<=size-1;j++) {   // init the j with 1st index from last 
            if(key>=array[j]) {   // compare the key with previous elements till it finds the last element
                resultArray[i] = resultArray[j]+1;
                break;
            }
        }
    }
    return resultArray;
}

int* ArrayWithNumberOfSmallerNumOfElementToRight(int Array[],int size) {
	int* newarry = new int[size];
	memset(newarry,0,sizeof(int)*(size+1));
	newarry[size] = 0;
	for(int i = size-2;i>=0;i--) {
		int j = i; // to traverse in the sub loop till end of array 
		int k = i; // Keep track of new array index 
		while(j<size-1){
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
/////////////////////////////////////////////////////////////////////////////////
int findnumberOfSmallItem(int* array,int size) {
	int count = 0;
	for(int i = 1;i<size;i++) {
		if(array[i]<array[0]) count++;
	}
	return count;
}
 void printLeftSmallestCountArray(int array[],int size,int resultArray[]) {
//[3, 4, 9, 6, 1]
	resultArray[size-1] = 0;
	for(int i = size-2;i>=0;i--) {
		int smallest = findnumberOfSmallItem(&array[i],size-i);
		resultArray[i] = smallest;
	}
	for(int i = 0;i<size;i++) {
		cout<<resultArray[i]<<endl;
	}
	
}
/////////////////////////////////////////////////////////////////////////////////
int main() {
	int array[] = {4,3,9,2,6,1};
	//int array[] = {1, 10, 9, 6, 29};  // use for testing 
	//int array[] = {3, 4, 9, 6, 1};    // use for testing
	int* resultArray = ArrayWithNumberOfSmallerNumOfElementToRight(array,sizeof(array)/sizeof(array[0]));
	printArray(resultArray,sizeof(array)/sizeof(array[0]));
	return 0;
}
// O/P : [3,2,2,1,1,0].
