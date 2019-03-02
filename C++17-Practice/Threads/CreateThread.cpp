#include<stdio.h>
#include<iostream>
#include<thread>
#include<pthread.h>

int global = 7; 
using namespace std;

class ThreadClass {
public:
	void operator()() {
		while(1) {
		    printf("\nCLASS %d",global);
			global = 8;
		}
	}
};

class Compare {
public:
    bool operator() (isPair& a, isPair& b) {
        if(strcmp(a.second.c_str(),b.second.c_str())>0) return true;
	    return false;
    }
};

void func(int* p) {
	while(1) {
		printf("\nFUNC %d",*p);
		global = 7;
	}
}

int main() {
	static int a;
	thread objClass((ThreadClass()));
	thread objFunc(func,&a);
	if(objClass.joinable()) {
//	    objClass.join();
	     //objClass.detach();
	}
	if(objFunc.joinable()) {
	//    objFunc.join();
	     //objFunc.detach();
	}

	int status;
	pthread_exit(&status);
	return 0;
}