#include<stdio.h>
#include<iostream>
#include<map>
#include<string>
#include <bits/stdc++.h> 
using namespace std;
string kthMostFrequentInString(const string& s,int k) {
	stringstream ss(s);
	string word;
	map<string,int> stringMap;
	map<int,string> rankingMap;
	while(ss>>word) {
		stringMap[word]++;
		
	}
	for(auto itr:stringMap) {
		cout<<itr.first <<" => " <<itr.second<<endl;
		rankingMap.insert(make_pair(itr.second,itr.first));
	}
	int i = 1;
	printf("\n---------------------------------\n");
	for(auto l=rankingMap.rbegin();l!=rankingMap.rend();l++) {
		cout<< l->second << endl;
		if(i==k) {
			return l->second;
		}
		i++;
	}
	return "NoResult" ;
}


string kthMostNonFrequentInString(const string& s,int k) {
	stringstream ss(s);
	string word;
	map<string,int> stringMap;
	map<int,string> rankingMap;
	while(ss>>word) {
		stringMap[word]++;
		
	}
	for(auto itr:stringMap) {
		cout<<itr.first <<" => " <<itr.second<<endl;
		rankingMap.insert(make_pair(itr.second,itr.first));
	}
	int i = 1;
	printf("\n---------------------------------\n");
	for(auto l=rankingMap.begin();l!=rankingMap.end();l++) {
		cout<< l->second << endl;
		if(i==k) {
			return l->second;
		}
		i++;
	}
	return "NoResult" ;
}
int main() {
	int k = 3;
	string kthMostFrequesntStr = kthMostFrequentInString("om Shree Ganeshaya Namaha om om Shree om maruthi Namaha om Shree",k);
	cout<<endl<<k<<"th most frequent "<< endl<<kthMostFrequesntStr<<endl;
	string kthMostNonFrequesntStr = kthMostNonFrequentInString("om Shree Ganeshaya Namaha om om Shree om maruthi Namaha om Shree",k);
	cout<<endl<<k<<"th most Non frequent "<< endl<<kthMostNonFrequesntStr<<endl;
	return 0;
}
