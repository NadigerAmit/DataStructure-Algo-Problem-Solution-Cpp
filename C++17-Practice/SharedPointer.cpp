
/*
What is std::shared_ptr<> ?
shared_ptr is a kind of Smart Pointer class provided by c++11, that is smart enough to automatically delete the associated pointer
when its not used anywhere. Thus helps us to completely remove the problem of memory leaks and dangling Pointers.

shared_ptr and Shared Ownership:
It follows the concept of Shared Ownership i.e. different shared_ptr objects can be associated with same pointer and internally
uses the reference counting mechanism to achieve this.

Each shared_ptr object internally points to two memory locations,
1.) Pointer to the object

2.) Pointer to control data that is used for reference counting

How Shared Ownership works with the help of Reference Counting:
When a new shared_ptr object is associated with a pointer,then in its constructor it increases the refernce count associated 
with this pointer by 1.

When any shared_ptr object goes out of scope then in its destructor it decrements the reference count of the associated pointer by 1.
If reference count becomes 0 then it means no other shared_ptr object is associated with this memory, in that case it deletes that 
memory using “delete” function.
*/
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
