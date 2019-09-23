/*
Good read:
https://www.geeksforgeeks.org/auto_ptr-unique_ptr-shared_ptr-weak_ptr-2/

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
using namespace std;
 
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
	unique_ptr<int> ptr1;
 
	// Check if unique pointer object is empty
	if(!ptr1)
		cout<<"ptr1 is empty"<<endl;
 
	// Check if unique pointer object is empty
	if(ptr1 == nullptr)
		cout<<"ptr1 is empty"<<endl;
 
	// can not create unique_ptr object by initializing through assignment
	// unique_ptr<Task> taskPtr2 = new Task(); // Compile Error
 
	// Create a unique_ptr object through raw pointer
	unique_ptr<Task> taskPtr(new Task(23));
 
	// Check if taskPtr is empty or it has an associated raw pointer
	if(taskPtr != nullptr)
		cout<<"taskPtr is  not empty"<<endl;
 
	//Access the element through unique_ptr
	cout<<taskPtr->mId<<endl;
 
	cout<<"Reset the taskPtr"<<endl;
	// Reseting the unique_ptr will delete the associated
	// raw pointer and make unique_ptr object empty
	taskPtr.reset();
 
	// Check if taskPtr is empty or it has an associated raw pointer
	if(taskPtr == nullptr)
		cout<<"taskPtr is  empty"<<endl;
 
 
	// Create a unique_ptr object through raw pointer
	unique_ptr<Task> taskPtr2(new Task(55));
 
	if(taskPtr2 != nullptr)
		cout<<"taskPtr2 is  not empty"<<endl;
 
	// unique_ptr object is Not copyable
	//taskPtr = taskPtr2; //compile error
 
	// unique_ptr object is Not copyable
	//unique_ptr<Task> taskPtr3 = taskPtr2;
 
	{
		// Transfer the ownership
 
		unique_ptr<Task> taskPtr4 = move(taskPtr2);
 
 
		if(taskPtr2 == nullptr)
			cout<<"taskPtr2 is  empty"<<endl;
 
		// ownership of taskPtr2 is transfered to taskPtr4
		if(taskPtr4 != nullptr)
			cout<<"taskPtr4 is not empty"<<endl;
 
		cout<<taskPtr4->mId<<endl;
 
		//taskPtr4 goes out of scope and deletes the assocaited raw pointer
	}
 
	// Create a unique_ptr object through raw pointer
	unique_ptr<Task> taskPtr5(new Task(55));
 
	if(taskPtr5 != nullptr)
		cout<<"taskPtr5 is not empty"<<endl;
 
	// Release the ownership of object from raw pointer
	Task * ptr = taskPtr5.release();
 
	if(taskPtr5 == nullptr)
		cout<<"taskPtr5 is empty"<<endl;
 
	cout<<ptr->mId<<endl;
 
	delete ptr;
 
	return 0;
}

/*
auto_ptr, unique_ptr, shared_ptr and weak_ptr
Prerequisite – Smart Pointers
C++ libraries provide implementations of smart pointers in following types:

auto_ptr
unique_ptr
shared_ptr
weak_ptr
They all are declared in a memory header file.

auto_ptr

This class template is deprecated as of C++11. unique_ptr is a new facility with a similar functionality, but with improved security.
auto_ptr is a smart pointer that manages an object obtained via new expression and deletes that object when auto_ptr itself is destroyed.
An object when described using auto_ptr class it stores a pointer to a single allocated object which ensures that when it goes out of scope, 
the object it points to must get automatically destroyed. It is based on exclusive ownership model i.e. two pointers of the same type can’t point
to the same resource at the same time. As shown in the below program, copying or assigning of pointers changes the ownership i.e. source pointer 
has to give ownership to the destination pointer.
The copy constructor and the assignment operator of auto_ptr do not actually copy the stored pointer instead they transfer it, leaving the first auto_ptr object empty. This was one way to implement strict ownership so that only one auto_ptr object can own the pointer at any given time i.e. auto_ptr should not be used where copy semantics are needed.

Why is auto_ptr deprecated?
It takes ownership of the pointer in a way that no two pointers should contain the same object. 
Assignment transfers ownership and resets the rvalue auto pointer to a null pointer.
Thus, they can’t be used within STL containers due to the aforementioned inability to be copied.


unique_ptr:

unique_ptr was developed in C++11 as a replacement for auto_ptr.
unique_ptr is a new facility with similar functionality, but with improved security (no fake copy assignments), 
added features (deleters) and support for arrays. It is a container for raw pointers. 
It explicitly prevents copying of its contained pointer as would happen with normal assignment i.e. it allows exactly one owner of the underlying pointer.
So, when using unique_ptr there can only be at most one unique_ptr at any one resource and when that unique_ptr is destroyed, 
the resource is automatically claimed. Also, since there can only be one unique_ptr to any resource, 
so any attempt to make a copy of unique_ptr will cause a compile-time error.

 unique_ptr<A> ptr1 (new A);

 // Error: can't copy unique_ptr
 unique_ptr<A> ptr2 = ptr1;    
But, unique_ptr can be moved using the new move semantics i.e. using move() function to transfer ownership of the contained pointer to another unique_ptr.

// Works, resource now stored in ptr2
unique_ptr<A> ptr2 = move(ptr1); 
So, it’s best to use unique_ptr when we want a single pointer to an object that will be reclaimed when that single pointer is destroyed.

When to use unique_ptr?
Use unique_ptr when you want to have single ownership(Exclusive) of the resource. Only one unique_ptr can point to one resource. 
Since there can be one unique_ptr for single resource its not possible to copy one unique_ptr to another.


shared_ptr:

A shared_ptr is a container for raw pointers. It is a reference counting ownership model i.e. it maintains the reference count of its contained pointer in cooperation with all copies of the shared_ptr.
So, the counter is incremented each time a new pointer points to the resource and decremented when the destructor of the object is called.

Reference Counting: It is a technique of storing the number of references, pointers or handles to a resource such as an object, block of memory, disk space or other resources.

An object referenced by the contained raw pointer will not be destroyed until reference count is greater than zero i.e. until all copies of shared_ptr have been deleted.
So, we should use shared_ptr when we want to assign one raw pointer to multiple owners.
When to use shared_ptr?
Use shared_ptr if you want to share ownership of a resource. Many shared_ptr can point to a single resource. 
shared_ptr maintains reference count for this propose. when all shared_ptr’s pointing to resource goes out of scope the resource is destroyed.

weak_ptr

A weak_ptr is created as a copy of shared_ptr. It provides access to an object that is owned by one or more shared_ptr instances but does not participate in reference counting. 
The existence or destruction of weak_ptr has no effect on the shared_ptr or its other copies. It is required in some cases to break circular references between shared_ptr instances.


Cyclic Dependency (Problems with shared_ptr): Let’s consider a scenario where we have two classes A and B, both have pointers to other classes. 
So, it’s always like A is pointing to B and B is pointing to A. Hence, use_count will never reach zero and they never get deleted.

So, in case of shared_ptr because of cyclic dependency use_count never reaches zero which is prevented using weak_ptr, 
which removes this problem by declaring A_ptr as weak_ptr, thus class A does not own it, only have access to it and 
we also need to check the validity of object as it may go out of scope. In general, it is a design issue.

When to use weak_ptr?
When you do want to refer to your object from multiple places – for those references for which it’s ok to ignore and deallocate (so they’ll just note the object is gone when you try to dereference).
*/