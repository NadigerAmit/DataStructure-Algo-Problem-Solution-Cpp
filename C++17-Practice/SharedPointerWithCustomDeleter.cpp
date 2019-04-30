/*

When a shared_ptr object goes out of scope, its destructor is called. Inside its destructor it decrements the reference
count by 1 and if new value of reference count is 0 then it deletes the associated raw pointer.

To delete the internal raw pointer in destructor, by default shared_ptr calls the delete() function i.e. delete ptr. 
But its not always that we want to use delete function in destruction, there can be other requirements too like,

If shared_ptr object points to an array instead of a simple pointer, we need to delete using delete[] insted of just delete.

Adding custom deleter to shared_ptr<>
In such case we can pass a callback to shared_ptr’s constructor, that will be called from its destructor for deletion 

In below example we use deleter as custom fun for deleting . which is passed as a last argument in shared_ptr as below:
std::shared_ptr<Test> p1(new Test[5],deleter);

*/

#include<stdio.h>
#include<iostream>
#include<memory>

using namespace std;
class Test {
	public:
	Test() {
		cout<<"Constructor"<<endl;
	}
	~Test() {
		cout<<"Destructor"<<endl;
	}
};

void deleter(Test* ptr) {
	delete[] ptr;
}

int main() {
	std::shared_ptr<Test> p1(new Test[5],deleter);
	return 0;
}