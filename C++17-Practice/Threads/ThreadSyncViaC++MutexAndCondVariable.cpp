#include<stdio.h>
#include<thread>
#include<iostream>
#include<functional>
#include <mutex>
#include <condition_variable> // std::condition_variable
using namespace std;

std::mutex mtx;
std::condition_variable cv;

void threadFun1() {
	std::unique_lock<std::mutex> lck(mtx,std::defer_lock);
    while(1) {
        lck.lock();
           printf("Om Shree Ganeshaya Namah\n");
	       cv.notify_all();
	       cv.wait(lck);
	   lck.unlock();;
    }
};

void threadFun2() {
	std::unique_lock<std::mutex> lck(mtx,std::defer_lock);
    while(1) {
         lck.lock();
             printf("Om Namah Shivaya\n");
		     cv.notify_all();
	         cv.wait(lck);
	     lck.unlock();
    }
}

int main() {

   // std::unique_lock lk(mutex,std::defer_lock);
    //pthread_cond_init(&cond,nullptr);
    std::thread thread1(threadFun1);
    std::thread thread2(threadFun2);
	thread1.join();
	thread2.join();

    return 0;
}


