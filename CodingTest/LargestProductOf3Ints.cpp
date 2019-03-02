#include<stdio.h>
#include<set>
#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;

int largestProduct(vector<int>& array) {
	sort(array.begin(),array.end());
	int numOfIntsToConsider = 4;
	int ForewardProduct = 1;
	int ReverseProduct = 1;
	int product = 1;
	auto BeginNum = array.begin();
	auto Endnum = array.end();
	Endnum--;
	while(numOfIntsToConsider>0) {
		if(*BeginNum==0) {
			if(ForewardProduct<0) {
				ForewardProduct = 1;
				numOfIntsToConsider++;
			}
			break;
		}
		ForewardProduct *= (*BeginNum);
	    printf("ForewardProduct = %d",ForewardProduct);
		auto nextNum = BeginNum++;
		if(nextNum == array.end()) break;
		if(product<0 && (*nextNum>=0)) {
			ForewardProduct = ForewardProduct/(*BeginNum);
			break; // start from the end;
		} else if(product>0) {
			numOfIntsToConsider--;
			break;
		}
		numOfIntsToConsider--;
	}
	product = ForewardProduct;
	printf("\n Product outside 1st loop = %d\n",product);
	num = array.end();
	num--;
	while(numOfIntsToConsider>0) {
		printf("\n in 2nd loop num = %d and numOfIntsToConsider = %d",*num,numOfIntsToConsider);
		product *= (*num);
		num--;
		numOfIntsToConsider--;
	}
	return product;
}
	
int largestProductWithSet(vector<int>& array) {
	multiset<int> intSet;
	for(auto i:array) {
		intSet.insert(i);
	}
	for(auto i:intSet) {
		cout<<i<<endl;
	}
	int numOfIntsToConsider = 4;
	auto num = intSet.begin();
	int product = 1;
	while(numOfIntsToConsider>0) {
		if(*num==0) {
			if(product<0) {
				product = 1;
				numOfIntsToConsider++;
			}
			break;
		}
		product *= (*num);
		printf("product = %d",product);
		auto nextNum = num++;
		if(nextNum == intSet.end()) break;
		if(product<0 && (*nextNum>=0)) {
			product = product/(*num);
			break; // start from the end;
		} else if(product>0) {
			numOfIntsToConsider--;
			break;
		}
		numOfIntsToConsider--;	
	}
	printf("\n Product outside 1st loop = %d\n",product);
	num = intSet.end();
	num--;
	while(numOfIntsToConsider>0) {
		printf("\n in 2nd loop num = %d and numOfIntsToConsider = %d",*num,numOfIntsToConsider);
		product *= (*num);
		num--;
		numOfIntsToConsider--;
	}
	return product;
}

int main() {
	vector<int> array = {-10,-2,1,3,5,2,0};
	int gratestProduct = largestProduct(array);
	printf("\n gratest product = %d",gratestProduct);
}