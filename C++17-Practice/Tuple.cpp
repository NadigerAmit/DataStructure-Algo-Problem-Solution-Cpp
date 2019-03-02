#include<stdio.h>
#include<iostream>
#include<tuple>

using namespace std;

tuple<int,float,char> x() { return make_tuple<int,float,char>(5,5.2f,'c'); }

void structureBinidingDemo() {
	auto [a,b,c] = x();
	cout<<"structureBinidingDemo \n";
	cout<<get<0>(x());
}

int main() {
	tuple<int,int,string> t(37,1,"Om Shree Ganeshaya Namah");
	cout<<get<0>(t) <<" --"<<get<1>(t) <<"--" <<get<2>(t);
	structureBinidingDemo();
	return 0;
}