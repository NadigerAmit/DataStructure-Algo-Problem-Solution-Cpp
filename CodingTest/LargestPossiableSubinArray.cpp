#include<stdio.h>
#include<iostream>

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