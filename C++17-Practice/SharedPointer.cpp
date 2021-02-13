
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

/*
Article Link:
http://www.vishalchovatiya.com/unique_ptr-with-example-in-c/

Referances:
https://www.learncpp.com/cpp-tutorial/15-1-intro-to-smart-pointers-move-semantics/
https://stackoverflow.com/questions/106508/what-is-a-smart-pointer-and-when-should-i-use-one
https://docs.microsoft.com/en-us/cpp/cpp/smart-pointers-modern-cpp?view=vs-2017

Brief

Prior to C++11, the standard provided std::auto_ptr. Which had some limitations. But from C++11, standard provided many smart pointers classes. 
Understanding unique_ptr with example in C++ requires an understanding of move semantics which I have discussed here & here.

But before all these nuisances, we will see “Why do we need smart pointer in 1st place?”:

Why do we need smart pointers?
*******************************************************************
void func()
{
    Resource *ptr = new Resource;
    int x;
    std::cout << "Enter an integer: ";
    std::cin >> x;
    if (x == 0)
        throw 0; // the function returns early, and ptr won't be deleted!
    if (x < 0)
        return; // the function returns early, and ptr won't be deleted!
    // do stuff with ptr here
    delete ptr;
}
*******************************************************************
In the above code, the early return or throw statement, causing the function to terminate without variable ptr being deleted.
Consequently, the memory allocated for variable ptr is now leaked (and leaked again every time this function is called and returns early).
These kinds of issues occur because pointer variables have no inherent mechanism to clean up after themselves.
Following class cleans-up automatically when sources are no longer in use:
*******************************************************************
smart_ptr aka std::auto_ptr from C++98
template<class T>
class smart_ptr
{
    T* m_ptr;
public:
    smart_ptr(T* ptr=nullptr):m_ptr(ptr){}
    ~smart_ptr()
    {
        delete m_ptr;
    }
    T& operator*() const { return *m_ptr; }
    T* operator->() const { return m_ptr; }
};
Now, let’s go back to our func() example above, and show how a smart pointer class can solve our challenge:
class Resource
{
public:
    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource destroyed\n"; }
};
void func()
{
    smart_ptr<Resource> ptr(new Resource); // ptr now owns the Resource
    int x;
    std::cout << "Enter an integer: ";
    std::cin >> x;
    if (x == 0)
        throw 0;
    if (x < 0)
        return;
    // do stuff with ptr here
    // dont care about deallocation
}
int main()
{
    try{
      func();
    }
    catch(int val){}
    return 0;
}
*******************************************************************
Output
Resource acquired
Hi!
Resource destroyed
*******************************************************************
Note: that even in the case where the user enters zero and the function terminates early, the Resource is still properly deallocated.
Because of the ptr variable is a local variable. ptr destroys when the function terminates (regardless of how it terminates).
And because of the smart_ptr destructor will clean up the Resource, we are assured that the Resource will be properly cleaned up.
There is still some problem with our code. Like:
int main()
{
    smart_ptr<Resource> res1(new Resource);
    smart_ptr<Resource> res2(res1); // Alternatively, don't initialize res2 and then assign res2 = res1;
    return 0;
}
Output
Resource acquired
Resource destroyed
Resource destroyed
In this case destructor of our Resource object will be called twice which can crash the program.
What if, instead of having our copy constructor and assignment operator copy the pointer (“copy semantics”), 
we instead transfer/move ownership of the pointer from the source to the destination object? This is the core idea behind move semantics. 
Move semantics means the class will transfer ownership of the object rather than making a copy.
Let’s update our smart_ptr class to show how this can be done:

*******************************************************************
template<class T>
class smart_ptr
{
    T* m_ptr;
public:
    smart_ptr(T* ptr=nullptr) :m_ptr(ptr) {}
    ~smart_ptr()
    {
        delete m_ptr;
    }
    // copy constructor that implements move semantics
    smart_ptr(smart_ptr& a) // note: not const
    {
        m_ptr = a.m_ptr; // transfer our dumb pointer from the source to our local object
        a.m_ptr = nullptr; // make sure the source no longer owns the pointer
    }
    // assignment operator that implements move semantics
    smart_ptr& operator=(smart_ptr& a) // note: not const
    {
        if (&a == this)
            return *this;
        delete m_ptr; // make sure we deallocate any pointer the destination is already holding first
        m_ptr = a.m_ptr; // then transfer our dumb pointer from the source to the local object
        a.m_ptr = nullptr; // make sure the source no longer owns the pointer
        return *this;
    }
    T& operator*() const { return *m_ptr; }
    T* operator->() const { return m_ptr; }
};
class Resource
{
public:
    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource destroyed\n"; }
};
int main()
{
    smart_ptr<Resource> res1(new Resource);
    smart_ptr<Resource> res2(res1);
    return 0;
}
*******************************************************************
Output
Resource acquired
Resource destroyed
*******************************************************************
std::auto_ptr, and why to avoid it
What we have seen above as smart_ptr is basically an std::auto_ptr which was introduced in C++98, was C++’s first attempt at a standardized smart pointer.
However, std::auto_ptr (and our smart_ptr class) has a number of problems that make using it dangerous.
Because std::auto_ptr implements move semantics through the copy constructor and assignment operator, passing an std::auto_ptr by value to a function will cause your 
resource to get moved to the function parameter (and be destroyed at the end of the function when the function parameters go out of scope). 
Then when you go to access your std::auto_ptr argument from the caller (not realizing it was transferred and deleted), you’re suddenly dereferencing a null pointer. Crash!
std::auto_ptr always deletes its contents using non-array delete. 
This means std::auto_ptr won’t work correctly with dynamically allocated arrays, because it uses the wrong kind of deallocation. 
Worse, it won’t prevent you from passing it a dynamic array, which it will then mismanage, leading to memory leaks.
Because of the above-mentioned shortcomings, std::auto_ptr has been deprecated in C++11, and it should not used. 
In fact, std::auto_ptr slated for complete removal from the standard library as part of C++17!
Overriding the copy semantics to implement move semantics leads to weird edge cases and inadvertent bugs. Because of this, in C++11, the concept of “move” formally defined.
And “move semantics” added to the language to properly differentiate copying from moving.
In C++11, std::auto_ptr has been replaced by a bunch of other types of “move-aware” smart pointers: std::scoped_ptr, std::unique_ptr, std::weak_ptr, and std::shared_ptr.
We’ll also explore the two most popular of these: std::unique_ptr (which is a direct replacement for std::auto_ptr) and std::shared_ptr.

std::unique_ptr with example in C++11
===========================================

std::unique_ptr is the C++11 replacement for std::auto_ptr. It is used to manage use to manage any dynamically allocated object not shared by multiple objects. 
That is, std::unique_ptr should completely own the object it manages, not share that ownership with other classes.

We can convert our smart_ptr we designed above into std::unique_ptr.
And for that one thing, we can do is delete the copy constructor & assignment operator so that no one can copy smart pointer.

As we are not allowing a copy of smart pointer we can’t pass our smart pointer to any function by value or return by value. And this is not good design.
To pass or return by value, we can add move constructor & move assignment operator, so that while passing or returning by value,
we would have to transfer ownership through move semantics. This way we can also ensure single ownership throughout the lifetime of the object.

*******************************************************************
template<class T>
class smart_ptr
{
    T* m_ptr;
public:
    smart_ptr(T* ptr = nullptr) : m_ptr(ptr){}
    ~smart_ptr()
    {
        delete m_ptr;
    }
    // Copy constructor
    smart_ptr(const smart_ptr& a) = delete;
    // Move constructor
    smart_ptr(smart_ptr&& a) : m_ptr(a.m_ptr)
    {
        a.m_ptr = nullptr;
    }
    // Copy assignment
    smart_ptr& operator=(const smart_ptr& a) = delete;
    // Move assignment
    smart_ptr& operator=(smart_ptr&& a)
    {        
        if (&a == this)
            return *this;
        delete m_ptr;
        m_ptr = a.m_ptr;
        a.m_ptr = nullptr;
        return *this;
    }
    T& operator*() const { return *m_ptr; }
    T* operator->() const { return m_ptr; }
};
class Resource
{
public:
    Resource() { std::cout << "Resource acquired\n"; }
    ~Resource() { std::cout << "Resource destroyed\n"; }
};
smart_ptr<Resource> func(smart_ptr<Resource> temp) 
{
  // Do something
  return temp;
}
int main()
{
    smart_ptr<Resource> res1(new Resource);
    // smart_ptr<Resource> res3 = res1; // Won't compile, as copy contructor is deleted
    smart_ptr<Resource> res3 = func(std::move(res1)); // calls move semantics
    return 0;
}
*******************************************************************
Output
Resource acquired
Resource destroyed
*******************************************************************
This is not the exact implementation of std::unique_ptr as there is deleter, implicit cast to bool & other security features included in an actual implementation, but this gives you a bigger picture of how std::unique_ptr is implemented.

*******************************************************************
Referances:
*******************************************************************
https://www.learncpp.com/cpp-tutorial/15-1-intro-to-smart-pointers-move-semantics/
https://stackoverflow.com/questions/106508/what-is-a-smart-pointer-and-when-should-i-use-one
https://docs.microsoft.com/en-us/cpp/cpp/smart-pointers-modern-cpp?view=vs-2017

*/
