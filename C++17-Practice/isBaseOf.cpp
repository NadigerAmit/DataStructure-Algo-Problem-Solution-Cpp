#include<stdio.h>
#include<iostream>

using namespace std;
class P {
	int num;
};
class D:public P {
	int num1;
};
class I {
	P p;
};

int main() {
	P p;
	D d;
	I i;
	cout<<"is_base_of<p,d>::value = "<<is_base_of<P,D>::value<<endl;
	cout<<"is_base_of<d,p>::value = "<<is_base_of<D,P>::value<<endl;
	cout<<"is_base_of<i,p>::value = "<<is_base_of<I,P>::value<<endl;
	return 0;
}