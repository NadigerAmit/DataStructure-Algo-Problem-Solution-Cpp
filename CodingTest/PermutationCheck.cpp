/*
PermCheck
Check whether array A is a permutation.
A non-empty array A consisting of N integers is given.

A permutation is a sequence containing each element from 1 to N once, and only once.

For example, array A such that:

    A[0] = 4
    A[1] = 1
    A[2] = 3
    A[3] = 2
is a permutation, but array A such that:

    A[0] = 4
    A[1] = 1
    A[2] = 3
is not a permutation, because value 2 is missing.

The goal is to check whether array A is a permutation.

Write a function:

int solution(vector<int> &A);

that, given an array A, returns 1 if array A is a permutation and 0 if it is not.

For example, given array A such that:

    A[0] = 4
    A[1] = 1
    A[2] = 3
    A[3] = 2
the function should return 1.

Given array A such that:

    A[0] = 4
    A[1] = 1
    A[2] = 3
the function should return 0.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
each element of array A is an integer within the range [1..1,000,000,000].

*/


#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include<set>

using namespace std;

int PermCheck(vector<int>& v) {
    set<int> s;
    for(int i : v) {
        s.insert(i);
    }
    int prev_num = 0;
    int current_num = 0;
    for(auto i = s.begin();i!=s.end();i++) {
        if(i == s.begin()) {
            prev_num = *i;
            continue;
        }
        current_num = *i;
        if(prev_num+1 != current_num) {
            return 0;
        }
        prev_num = current_num;
    }
    return 1;
}
int main() {
    vector<int> v = {4,1,3,2};
    int min = PermCheck(v);
    cout<<"minimum Distance = "<<min<<endl;
}