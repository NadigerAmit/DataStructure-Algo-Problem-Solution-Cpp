
/*
Below program shows how to pass the class member function to thread for thread creation .
*/
#include<stdio.h>
#include<iostream>
#include<pthread.h>

using namespace std;

class ThreadClass {

	public:
		void* execute();
		void* execute1();
		static void* threadFunc(void* arg);
};

void* ThreadClass::execute() {
	 cout<<" \ninsidse the execute without param - thread member function  " <<pthread_self()<<endl<<"\n"; 
	return nullptr;
}

void* ThreadClass::execute1() {
	cout<<" \ninsidse the execute - thread member function =>" <<pthread_self()<<endl<<"\n";
	return nullptr;
}

void* ThreadClass::threadFunc(void* arg) {
	cout<<" \ninsidse the threadFunc - thread static function => " <<pthread_self()<<endl<<"\n";
	return nullptr;
}

typedef void* (*THREADFUNC)(void* ptr);

int main() {
	pthread_t threadId1,threadId2;
	ThreadClass* threadPtr = new ThreadClass();
	
	//THREADFUNC callbackFunc = (THREADFUNC)&ThreadClass::execute;

	int id1 = pthread_create(&threadId1,nullptr,(THREADFUNC)&ThreadClass::execute,threadPtr); // passing the this pointer to execute() i.e threadPtr
	int id2 = pthread_create(&threadId2,nullptr,ThreadClass::threadFunc,nullptr);
	
	cout<<" \ninsidse the main - function =>" <<pthread_self()<<endl<<"\n";
	pthread_exit(nullptr);
	return 0;
}
