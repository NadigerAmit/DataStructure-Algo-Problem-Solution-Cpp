#include<stdio.h>
#include<iostream>
#include<vector>
//#define nullptr NULL

#ifdef __cplusplus
    extern "C" {
#endif 
// Co code goes here.
#ifdef __cplusplus
	}
#endif 
class Test {
	private :
	volatile int* ptr;
	public:
	Test() {
		ptr = new int;
		printf("\nTest Constructor ptr = %u",ptr);
	}
	Test(const Test& obj) {
		printf("\n in copy const\n");
		ptr = new int;
	}

	Test(Test&& obj) {    // Move constructor
		printf("\n in Move constructoir\n");
		ptr = obj.ptr;
		obj.ptr = nullptr;
	}

	Test& operator=(Test&& obj);  // move operator overloading.
	Test& operator=(const Test& obj); // assignment operator overloading 
	
	~Test() {
		if(ptr !=nullptr) {
			printf("\nTest Dest Deleting! ptr = %u",ptr);
			delete ptr;
			ptr = nullptr;
	//		printf("\nTest Dest Deleting! ptr = %u",ptr);
		}
		//printf("\nTest Dest");
	}
	
};

Test& Test::operator=(Test&& obj) {   // Move operator overloading 
	printf("\n in Move operator\n");
	ptr = obj.ptr;
	obj.ptr = nullptr;
	return *this;
}

Test& Test::operator=(const Test& obj) {  // assignment operator overloading 
	printf("\n in = overloading \n");
	ptr = new int;
	return *this;
}

Test getTest() {
	Test a;
	return a;
}
int main() {
	Test a;
	Test b;
	std::vector<Test> vecOfTestObj;
	//a  = getTest();
	vecOfTestObj.push_back(getTest());
	 b = getTest();
	 Test c = a;
	return 0;
}