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
	pthread_attr_t attr;
	 size_t stackSize = 0;
	 pthread_attr_getstacksize(&attr,&stackSize);
	 cout<<" \ninsidse the execute without param - thread member function  and stack size =>" <<pthread_self()<<" Stack size " << stackSize<<endl<<"\n";
	 
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
	//callbackFunc(threadPtr);

	int id1 = pthread_create(&threadId1,nullptr,(THREADFUNC)&ThreadClass::execute,nullptr);
	int id2 = pthread_create(&threadId2,nullptr,ThreadClass::threadFunc,nullptr);
	
	cout<<" \ninsidse the main - function =>" <<pthread_self()<<endl<<"\n";
	//printf("\n Address of the function %p\n",callbackFunc);
	
	printf("\n Address of the function using directly  %p\n",&ThreadClass::execute);
	pthread_exit(nullptr);
	return 0;
}