/*
Implement integer exponentiation. That is, implement the pow(x, y) function, where x and y are integers and returns x^y.

Do this faster than the naive method of repeated multiplication.

For example, pow(2, 10) should return 1024.
*/

#include<stdio.h>
#include<iostream>

int powerOf(int x , unsigned int y) {  // 
    int temp;
	if(y<=0) return 1;
	if(y==1) return x;
//	printf(" \n y = %d temp = %d",y,temp);
	temp = powerOf(x,y/2);
	
	if(y%2 ==0) {
		printf(" \n y = %d temp*temp = %d",y,temp*temp);
		return temp*temp;
	} else {
		printf(" \n y = %d x*temp*temp = %d",y,x*temp*temp);
		return x*temp*temp;
	}
}

int main() {
	int x = 2, y = 10;
	int p = powerOf(x,y);
	printf("\n Power of %d , %d  = %d",x,y,p);
	return 0;
}