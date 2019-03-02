#include<stdio.h>
#include<iostream>
void resetBoard();
void printBoard();

int const N = 4;
int board[N][N] = {0};

bool canBeAttackedByOtherQueen(int row ,int col) {
	for(int i = 0;i<N;i++) { // checking row and column
		if(board[row][i] == 1 || board[i][col] == 1) return true;
	}
	for (int i = 0;i<N;i++) {
		for (int j= 0;j<N;j++) {
			if(i+j == row+col) {
				if(board[i][j] == 1) return true; // right above and left below diagonal 
			}
			if(i-j == row-col) {
				if(board[i][j] == 1) return true;  // left above diagonal
			}
		}
	}
	return false;
}

bool SolveNQProblem(int numOfQueen) {
	if(numOfQueen == 0) return true; // base condition .
	for(int i = 0;i<N;i++) {
		for(int j = 0;j<N;j++) {
			if(!canBeAttackedByOtherQueen(i,j) && board[i][j] == 0) {
				board[i][j] = 1;
				if(SolveNQProblem(numOfQueen-1) == true) {
					return true;
				}
				board[i][j] = 0; // this is backtracking
			}
		}
	}
	return false;
}

int main() {
	resetBoard();
	if (SolveNQProblem(N)) {
	    printBoard();
	} else {
		printf("\n Solution dont exists\n");
	}
	return 0;
}

void resetBoard() {
	for(int i = 0;i<N;i++) {
		for(int j=0;j<N;j++) {
			board[i][j] = 0;
		}
	}
}

void printBoard() {
	for(int i = 0;i<N;i++) {
		for(int j=0;j<N;j++) {
			printf("%d ",board[i][j]);
		}
		printf("\n");
	}
}