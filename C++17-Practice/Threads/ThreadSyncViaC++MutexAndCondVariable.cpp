/*
Below program demonstrate the thread syncronization using C++ 11 -> mutex and condition variable 
Thread 1 prints even number starting from 0 by increating the shared global varaible  global.
Thread 2 prints odd number starting from 1 by increating the same shared global varaible  global..

*/
#include<stdio.h>
#include<thread>
#include<iostream>
#include<functional>
#include <mutex>
#include <condition_variable> // std::condition_variable
using namespace std;
int global = 0;

std::mutex mtx;
std::condition_variable cv;

void threadFun1() {
	std::unique_lock<std::mutex> lck(mtx,std::defer_lock);
    while(1) {
        lck.lock();
           printf("Thread 1 - Even %d \n",global++);
	       cv.notify_all();
	       cv.wait(lck);
	   lck.unlock();;
    }
};

void threadFun2() {
	std::unique_lock<std::mutex> lck(mtx,std::defer_lock);
    while(1) {
         lck.lock();
             printf("Thread 2 - Odd %d \n",global++);
		     cv.notify_all();
	         cv.wait(lck);
	     lck.unlock();
    }
}

int main() {
    std::thread thread1(threadFun1);
    std::thread thread2(threadFun2);
	thread1.join();
	thread2.join();
    return 0;
}
