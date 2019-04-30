/*
unique_ptr<> is one of the Smart pointer implementation provided by c++11 to prevent memory leaks. 
A unique_ptr object wraps around a raw pointer and its responsible for its lifetime. 
When this object is destructed then in its destructor it deletes the associated raw pointer.

unique_ptr has its -> and * operator overloaded, so it can be used similar to normal pointer.

unique_ptr<Task> object taskPtr accepts a raw pointer as arguments. 
Now when function will exit, this object will go out of scope and its destructor will be called. 
In its destructor unique_ptr object taskPtr deletes the associated raw pointer.

So, even if function is exited normally or abnormally (due to some exception), destructor of taskPtr will always be called. 
Hence, raw pointer will always get deleted and prevent the memory leak.


Unique Ownership of unique pointer
A unique_ptr object is always the unique owner of associated raw pointer. 
We can not copy a unique_ptr object, its only movable.
As each unique_ptr object is sole owner of a raw pointer, therefore in its destructor it directly deletes the associated pointer.
There is no need of any reference counting, therefore its very light.

Calling reset() function on a unique_ptr<> object will reset it i.e. 
it will delete the associated raw pointer and make unique_ptr<> object empty.

Transfering the ownership of unique_ptr object
We cannot copy a unique_ptr object, but we can move them. 
It means a unique_ptr object can transfer the owner ship of associated raw pointer to another unique_ptr object.
*/
#include <iostream>
#include <memory>
 
struct Task
{
	int mId;
	Task(int id ) :mId(id)
	{
		std::cout<<"Task::Constructor"<<std::endl;
	}
	~Task()
	{
		std::cout<<"Task::Destructor"<<std::endl;
	}
};
 
int main()
{
	// Empty unique_ptr object
	std::unique_ptr<int> ptr1;
 
	// Check if unique pointer object is empty
	if(!ptr1)
		std::cout<<"ptr1 is empty"<<std::endl;
 
	// Check if unique pointer object is empty
	if(ptr1 == nullptr)
		std::cout<<"ptr1 is empty"<<std::endl;
 
	// can not create unique_ptr object by initializing through assignment
	// std::unique_ptr<Task> taskPtr2 = new Task(); // Compile Error
 
	// Create a unique_ptr object through raw pointer
	std::unique_ptr<Task> taskPtr(new Task(23));
 
	// Check if taskPtr is empty or it has an associated raw pointer
	if(taskPtr != nullptr)
		std::cout<<"taskPtr is  not empty"<<std::endl;
 
	//Access the element through unique_ptr
	std::cout<<taskPtr->mId<<std::endl;
 
	std::cout<<"Reset the taskPtr"<<std::endl;
	// Reseting the unique_ptr will delete the associated
	// raw pointer and make unique_ptr object empty
	taskPtr.reset();
 
	// Check if taskPtr is empty or it has an associated raw pointer
	if(taskPtr == nullptr)
		std::cout<<"taskPtr is  empty"<<std::endl;
 
 
	// Create a unique_ptr object through raw pointer
	std::unique_ptr<Task> taskPtr2(new Task(55));
 
	if(taskPtr2 != nullptr)
		std::cout<<"taskPtr2 is  not empty"<<std::endl;
 
	// unique_ptr object is Not copyable
	//taskPtr = taskPtr2; //compile error
 
	// unique_ptr object is Not copyable
	//std::unique_ptr<Task> taskPtr3 = taskPtr2;
 
	{
		// Transfer the ownership
 
		std::unique_ptr<Task> taskPtr4 = std::move(taskPtr2);
 
 
		if(taskPtr2 == nullptr)
			std::cout<<"taskPtr2 is  empty"<<std::endl;
 
		// ownership of taskPtr2 is transfered to taskPtr4
		if(taskPtr4 != nullptr)
			std::cout<<"taskPtr4 is not empty"<<std::endl;
 
		std::cout<<taskPtr4->mId<<std::endl;
 
		//taskPtr4 goes out of scope and deletes the assocaited raw pointer
	}
 
	// Create a unique_ptr object through raw pointer
	std::unique_ptr<Task> taskPtr5(new Task(55));
 
	if(taskPtr5 != nullptr)
		std::cout<<"taskPtr5 is not empty"<<std::endl;
 
	// Release the ownership of object from raw pointer
	Task * ptr = taskPtr5.release();
 
	if(taskPtr5 == nullptr)
		std::cout<<"taskPtr5 is empty"<<std::endl;
 
	std::cout<<ptr->mId<<std::endl;
 
	delete ptr;
 
	return 0;
}