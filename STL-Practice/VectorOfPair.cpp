#include<stdio.h>
#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
bool myComparator(pair<int,string>&a ,
                   pair<int,string>&b) {
//	return (strcmp(const_cast<char*>(a.second),const_cast<char*>(b.second))<0?false:true);
	return (strcmp(a.second.c_str(),b.second.c_str())<0?true:false);
}

int main() {
	vector<pair<int,string>> personAgeVec;
	vector<int> age = {23,32,43,12,2,34};
	vector<string> person = {"om","Shree","Ganesha","Namah","Jsi","Bajarangbali"};
	for(int i =0;i<6;i++) {
		personAgeVec.push_back(make_pair(age[i],person[i]));
	}
	int i = 0;
	for(i =0;i<6;i++) {
		cout<<"Age = "<<personAgeVec[i].first <<"----"<<personAgeVec[i].second<<endl;
	}
	sort(personAgeVec.begin(),personAgeVec.end());
	printf("\n sorting based on age ");
	for( i =0;i<6;i++) {
		cout<<"Age = "<<personAgeVec[i].first <<"----"<<personAgeVec[i].second<<endl;
	}
	printf("\n sorting based on Name \n");
	sort(personAgeVec.begin(),personAgeVec.end(),myComparator);
	for(i =0;i<6;i++) {
		cout<<"Age = "<<personAgeVec[i].first <<"----"<<personAgeVec[i].second <<endl;
	}
	return 0;
}