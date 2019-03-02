#include<stdio.h>
#include<iostream>
#include<memory>

using namespace std;

class Test {
	public:
	Test(int a) {
		cout<<"\n Constructor \n";
	}
	~Test() {
		cout<<"\n Destructor \n";
	}
};

void fun() {
	//shared_ptr<Test> p1 = make_shared<Test>();
	shared_ptr<Test> p1 = make_shared<Test>(11);
	shared_ptr<Test> p2(new Test(10));
	p1 = nullptr;
	p2.reset();
	printf("\n In function %d",p1.use_count());
}

int main() {
	fun();
	return 0;
}