/*
Here is a C program to print a matrix helically. Printing a matrix helically means printing it in this spiral
fashion
 >-----------+
 |
 +---->--+ |
 | | |
 | | |
 | <---+ |
 | |
 +-----------+
*/

#include<stdio.h>
#include<iostream>

const int row = 6;
const int col = 6;
int colSize = col;
int rowSize = row;

int matrix[row][col] ;
void fillMatrix() {
	int count = 0;
	for(int i = 0;i<row;i++) {
		for(int j = 0;j<col;j++) {
			matrix[i][j] = count;
			count++;
		}
	}
}

void NormalPrintMatrix() {
	printf("\n Normal Printing \n");
	int count = 0;
	for(int i = 0;i<row;i++) {
		for(int j = 0;j<col;j++) {
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}
}

void printHelically() {
	printf("\n Helical Printing \n");
	int i,j,k,l;
	for(i=rowSize-1,j=0,l = colSize-1;i>0;i--,j++,l--) {
		//printf("i = %d l = %d\n ",i,l);
		for(k=j;k<l;k++) printf(" %d ",matrix[j][k]);
//		printf("\n");
		for(k=j;k<i;k++) printf(" %d ",matrix[k][l]);
	//	printf("\n");
		for(k=l;k>j;k--) printf(" %d ",matrix[i][k]);
//		printf("\n");
		for(k=i;k>j;k--) printf(" %d ",matrix[k][j]);
	}
}

int main() {
	fillMatrix();
	NormalPrintMatrix();
	printHelically();
	return 0;
}