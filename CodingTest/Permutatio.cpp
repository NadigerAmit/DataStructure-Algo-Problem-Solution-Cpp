#include<stdio.h>
#include<iostream>
#include<string>
#include <algorithm>
#include<set>
#include <cstring>

using namespace std;
void permuteHelper(string s,string chosen,set<string> alreadyChoosen) {
	cout<<"source = "<<s <<" ---- choosen = "<<chosen<<endl;
	if(s.empty()) {
		if(alreadyChoosen.find(chosen) != alreadyChoosen.end()) {
			// dont do anything , just ignore
		}else {
			cout<<chosen << endl;
			alreadyChoosen.insert(chosen);
		}
			
		
	} else {
		// choose/explore/unchoose
		for(int i =0;i<s.length();i++) {
			//choose
			char c = s[i]; // remove the char from source string put it athe end of choses
			chosen +=c; // adding at the end of chosesn
			// explore
			s.erase(i,1); // remove the character that wa put it in to end.
			printf(" i =%d Before= %c\n",i,c);
			permuteHelper(s,chosen,alreadyChoosen);
			printf(" i =%d After= %c\n",i,c);
			// Un-choose
			s.insert(i,1,c);
			chosen.erase(chosen.length()-1,1); // erase the last character that was inserted
		}
	}
}

void permuteString(string str,string choose) {
	set<string> alreadyChoosen;
	permuteHelper(str,choose,alreadyChoosen);
}

void permutionUsingInbuilt(string s) {
	set<string> alreadyChoosen;
	int len = s.length();
	char buff[10];
	strncpy(buff,s.c_str(),sizeof(buff));
	sort(buff,buff+len);
	do {
		cout<<buff<<endl;
	}while(next_permutation(buff,buff+len));
	return;
}

int main() {
	string str = "abc";
	//permuteString(str,"");
	permutionUsingInbuilt(str);
	return 0;
}