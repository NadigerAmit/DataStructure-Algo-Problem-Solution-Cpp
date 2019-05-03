#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

/*
Problem:

There exists a staircase with N steps, and you can climb up either 1 or 2 steps at a time. Given N, 
write a function that returns the number of unique ways you can climb the staircase. The order of the steps matters.

For example, if N is 4, then there are 5 unique ways:

1, 1, 1, 1
2, 1, 1
1, 2, 1
1, 1, 2
2, 2
What if, instead of being able to climb 1 or 2 steps at a time, you could climb any number from a set of positive integers X? 
For example, if X = {1, 3, 5}, you could climb 1, 3, or 5 steps at a time.
===================================================================================================================================
*/
/*
Solution:   1 or 2 steps at a time X(1,2)
N          possiable Num of ways:                                          pattern
0                  0                                                        0 or 1 <Base case , f(0) = 0>
1                  1                                                        0+1    <Base case , F(1) = 1>
2                  2 {(1,1 and 2)}                                          f(1)+1
3                  3 {(1,1,1),(1,2),(2,1)}                                  f(2) + f(1)
4                  5 {(1,1,1,1),(1,2,1),(2,1,1),(1,1,2),(2,2)}              f(3) + f(2)
:
:
:
n                  ?                                                        f(n-1)+f(n-2)
===================================================================================================================================                ?                                                        f(n-1)+f(n-2)   <= this is same as fibonacci series.
*/

int stracecaseClimbingWaysFor1_2(int n ,vector<int>& v) { // n = toal number of steps and V is vector for memoization.
    if(n==0) return 0;
    if(n==1) return 1;
    if(v[n]!=0) return v[n]; // this process is called memoization 
    v[n-1] = stracecaseClimbingWaysFor1_2(n-1,v);
    v[n-2] = stracecaseClimbingWaysFor1_2(n-2,v);
    return v[n-1]+v[n-2];
}

/*
Solution:   X = {1, 3, 5}, you could climb 1, 3, or 5 steps at a time.

N          possiable Num of ways:                                                                 pattern 
0                  0                                                                              0 or 1         <Base case , f(0) = 0>
1                  1                                                                              0+1            <Base case , F(1) = 1>
2                  1 {(1,1)}                                                                      f(1)           <Base case , F(2) = 1>
3                  2 {(1,1,1),(3))}                                                               f(2) + f(1)    <Base case , F(3) = 2>
4                  3 {(1,1,1,1),(1,3),(3,1)}                                                      f(3) + f(2)
5                  5 {(1,1,1,1,1),(1,3,1),(3,1,1)(1,1,3),(5)}                                     f(0)  +f(2) +f(3)    
6                  8 {(1,1,1,1,1,1),(1,3,1,1),(3,1,1,1)(1,1,3,1),(1,1,1,3)(5,1)(1,5),(3,3),()}    f(1)  +F(3) +f(5) = 1+2+5 = 8
:
:
n                  ?                                                                               f(n-5)+f(n-3)+f(n-1)         
*/

int stracecaseClimbingWaysFor1_3_5(int n ,vector<int>& v) { // n = toal number of steps 
    if(n==0) return 0;
    if(n<=2) return 1;
    if(v[n]!=0) return v[n];  // this is called memoization 
    int result  = stracecaseClimbingWaysFor1_3_5(n-1,v)+ stracecaseClimbingWaysFor1_3_5(n-3,v)+stracecaseClimbingWaysFor1_3_5(n-5,v);
    v[n] = result;  //  memoization 
    return result;
}

int main() {
    int n = 15;
    vector<int> v;
    v.resize(n+1);
    vector<int> v1;
    v1.resize(n+1);
    printf("\n stracecaseClimbingWaysFor1_2 for  %d",stracecaseClimbingWaysFor1_2(n,v));
    printf("\n stracecaseClimbingWaysFor1_3_5 for  %d",stracecaseClimbingWaysFor1_3_5(n,v1));
    return 0;
}





