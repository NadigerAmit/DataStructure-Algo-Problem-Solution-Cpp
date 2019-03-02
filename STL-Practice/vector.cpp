#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<map>
//#include<iterator>
using namespace std;
struct node {
	int num;
	map<int,string> hashMap;
};
using namespace std;
int main() {
	vector<int> vecInt = {1,21,32,43};
	vector<int*> vecIntPtr;
	vector<node*> testVect;
	vector<string> vecString = {"Om","Shree","GaneshayaNama","JaiBajarang Bali"};
	vector<int>::iterator itr ;
	for(itr = vecInt.begin();itr!= vecInt.end();itr++) {
		cout<<*itr <<" ";
	}
	cout<<"\n printing above values with auto same \n";
	for(itr = vecInt.begin();itr!= vecInt.end();itr++) {  // If we use iterator , it will point to the address of that location 
		cout<<*itr <<" ";                                 // we have to access using pointer i.e *.
	}
	cout<<endl;
	for(auto itr:vecInt) {
		cout<<itr <<" ";
	}
	vector<string>::iterator itr1;
	for(itr1 = vecString.begin();itr1!= vecString.end();itr1++) {
		cout<<*itr1<<" ";
	}
	int*p = new int;
	*p = 89;
	vecIntPtr.assign(2,p);
	*p = 98;
	printf("\nPrinting below with Auto \n");
	for(auto itr:vecIntPtr) {                       // if we use auto , the auto variable exactly resembles the object type . i.e type of vector is it , auto variable will point to int
		cout<<*itr;                                 // if we use auto to int* i.e pointer to verctor then variable will point to int.should access using *
	}
	vector<int*>::iterator itr2 ;
	for(itr2 = vecIntPtr.begin();itr2!= vecIntPtr.end();itr2++) {  // If we use iterator , it will point to the address of that location 
		cout<<*itr2 <<" ";                                 // we have to access using pointer i.e *.
	}
	cout<<"\nsize of testVect"<<vecInt.size();
    testVect.resize(6);
	if(testVect[7] == nullptr) {
		printf("\n nullptr reached \n");
		return 0;
	}
	cout<<"\nsize of testVect"<<testVect.size();

	return 0;
}