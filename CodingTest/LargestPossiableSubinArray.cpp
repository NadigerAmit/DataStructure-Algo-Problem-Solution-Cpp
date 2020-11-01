#include<stdio.h>
#include<iostream>

/* 
Kadane's algorithm scans the given array {\displaystyle A[1\ldots n]}{\displaystyle A[1\ldots n]} from left to right. 
In the {\displaystyle j}jth step, it computes the subarray with the largest sum ending at {\displaystyle j}j; this sum is maintained in variable current_sum.
[note 3] Moreover, it computes the subarray with the largest sum anywhere in {\displaystyle A[1\ldots j]}{\displaystyle A[1\ldots j]},
maintained in variable best_sum,[note 4] and easily obtained as the maximum of all values of current_sum seen so far, cf. line 7 of the algorithm.

Algorithm 
def max_subarray(numbers):
    """Find the largest sum of any contiguous subarray."""
    best_sum = 0  # or: float('-inf')
    current_sum = 0
    for x in numbers:
        current_sum = max(0, current_sum + x)  // if all numbers are negative , it retiurns -ve number 
        best_sum = max(best_sum, current_sum)
    return best_sum
    
*/
int max(int a,int b) {
	return a>b?a:b;
}
int largestPossiableSumOfArrayBy_KadaneAlgo(int array[],int size) {
	int currnetSum = 0;
	int bestSum = -12344;
	for(int i = 0;i<size;i++) {
		if(currnetSum<0 && currnetSum<array[i]) { // for negative numbers 
			currnetSum = array[i];
			bestSum = max(bestSum,currnetSum);
		} else {
			currnetSum = max(-12344,currnetSum+array[i]); // basically -ve infinity num should be compared.
			bestSum = max(bestSum,currnetSum);
		}
	}
	return bestSum;
}


int largestPossiableSumOfArray(int array[], int size) {
	int currentSum = array[0];
	int nextSum = 0;
	int biggestSum = currentSum;
	for(int i =1;i<size;i++) {
		printf("\narray[%d] = %d and currentSum = %d ",i,array[i],currentSum);
		if(array[i]>currentSum && currentSum<0) {
			nextSum = array[i];
		} else {
			nextSum = currentSum+array[i];
		}
		printf("nextSum = %d ",nextSum);
		if(nextSum>=currentSum) {
			currentSum = nextSum;
			if(currentSum>biggestSum) {
				printf("BiggestSum = %d \n",biggestSum,currentSum);
				biggestSum = currentSum;
			}
		} else {
			// reset currentSum 
			nextSum = 0;
			if(i<size-1)
			currentSum = array[++i];
		}
	}
	return (currentSum>biggestSum)?currentSum:biggestSum;
}
int main() {
	//int array[] = {-1,-1-3,4,1,3,2,-6,3,1,4,8,-1};
	int array[] = {-5,-4,-8,-1};
	printf("\nBiggestPossiable Sum = %d",largestPossiableSumOfArray(array,sizeof(array)/sizeof(array[0])));
	return 0;
}
