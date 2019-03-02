#include<stdio.h>
#include<iostream>
#include<vector>
#include<set>

using namespace std;

int main() {
	int a[] = {10, 5, 2, 7, 8, 7};
	set<int> SetOfInts;
	int k = 3;
	int max = a[0];
	vector<int> resultingArray;
	int i= 0;
	for(i=0;i<k;i++) {
		SetOfInts.insert(a[i]);
	}
	resultingArray.push_back(*SetOfInts.rbegin());
	SetOfInts.erase(a[i-k]);
	while(i<sizeof(a)/sizeof(a[0])) {
		SetOfInts.insert(a[i]);
		resultingArray.push_back(*SetOfInts.rbegin());
		SetOfInts.erase(a[i-k]);
		i++;
	}
	printf("\n sub array with max\n");
	for(auto j:resultingArray) {
		cout<<j<<endl;
	}
	return 0;
}