#include<stdio.h>
#include<iostream>

/*
Transpose of Matrix . 
input:
3,4,7,2
1,4,6,0
8,9,1,10

Output:
3,1,8
4,4,9
7,6,1
2,0,10
*/

using namespace std;

const int ROW = 3;
const int COL = 4;


int** getTranspose(int (&array)[ROW][COL] , int row ,int col) { // Pass by referance
	int **ptr = nullptr;
	ptr = new int*[col];
	for(int i = 0;i<col; i++) {
		ptr[i] = new int[row];
	}
	// now transpose logic 
	for(int i = 0;i<col;i++) {
		for(int j = 0;j<row;j++) {
			ptr[i][j] = array[j][i];
		}
	}
	return ptr;
}

void printMatrix(int (&array)[ROW][COL],int row ,int col ) { // pass by referance
    for(int i = 0;i<row;i++) {
		for(int j = 0;j<col;j++) {
			printf("%d ",array[i][j]);
		}
		printf("\n");
	}
}

void printMatrix(int **array,int row ,int col ) { // pass by pointer
    for(int i = 0;i<row;i++) {
		for(int j = 0;j<col;j++) {
			printf("%d ",array[i][j]);
		}
		printf("\n");
	}
}

int main() {
	int arr[ROW][COL];
	printf("\n Enter the elements ");
	for(int i = 0;i<ROW;i++) {
		for(int j = 0;j<COL;j++) {
			scanf("%d",&arr[i][j]);
		}
	}
	int** transposeAray = getTranspose(arr,ROW,COL);
	printf("\n Print of matrix \n");
	printMatrix(arr,ROW,COL);
	printf("\n Transpose of matrix \n");
	printMatrix(transposeAray,COL,ROW);
	return 0;
}

