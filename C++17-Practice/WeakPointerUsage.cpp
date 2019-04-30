
/*
https://thispointer.com//shared_ptr-binary-trees-and-the-problem-of-cyclic-references/

std::shared_ptr<Node> leftPtr;
    std::shared_ptr<Node> rightPtr;
    
    std::shared_ptr<Node> parentPtr; left and right child will be pointing to parents .

Now constructor will be called 3 times but there will be no call to destructor and that is a memory leak.

Reason of this problem with shared_ptr is cyclic references i.e.

If two objects refer to each other using shared_ptrs, then no one will delete the internal memory when they goes out of scope.

It happens because shared_ptr in its destructor after decrementing the reference count of associated memory checks if count is 0 
then it deletes that memory and if it’s greater than 1 then it means that any other shared_ptr is using this memory.

But in this kind of scenario these shared_ptrs will always found count greater than 0 in destructor.

Let’s reconfirm this for above example,

When ptr’s destructor is called,

o    It decrements the reference count by 1.

o    Then checks if current count is 0 but that is 2 because both left and right child has a shared_ptr object referencing to parent i.e. ptr.

o    Left and Right Child will be deleted only when memory for ptr will be deleted but that’s not going to happen because reference count is greater than 0.

o    Hence memory for neither ptr nor its children will be deleted. Therefore no destructor was called.

Now How to fix this problem?

Answer is using weak_ptr.
Weak_ptr allows sharing but not owning an object. It’s object is created by a shared_ptr

With weak_ptr object we cannot directly use operators * and -> to access the associated memory. 
First we have to create a shared_ptr through weak_ptr object by calling its lock() function,  then only we can use it.

Important Point: lock() can return empty shared_ptr if that shared_ptr us already deleted.
Improving our Binary tree example with weak_ptr
In case of cyclic references i.e. two objects refer to each other using shared_ptrs, change one object to contain weak_ptr instead of shared_ptr.
*/
#include <iostream>
#include <memory>
class Node
{
    int value;
    public:
    std::shared_ptr<Node> leftPtr;
    std::shared_ptr<Node> rightPtr;
    
    std::weak_ptr<Node> parentPtr; // Just Changed the shared_ptr to weak_ptr
    Node(int val) : value(val)     {
         std::cout<<"Contructor"<<std::endl;
    }
    ~Node()     {
         std::cout<<"Destructor"<<std::endl;
    }
};
int main() {
    std::shared_ptr<Node> ptr = std::make_shared<Node>(4);
    ptr->leftPtr = std::make_shared<Node>(2);
    ptr->leftPtr->parentPtr = ptr;
    ptr->rightPtr = std::make_shared<Node>(5);
    ptr->rightPtr->parentPtr = ptr;
    std::cout<<"ptr reference count = "<<ptr.use_count()<<std::endl;
    std::cout<<"ptr->leftPtr reference count = "<<ptr->leftPtr.use_count()<<std::endl;
    std::cout<<"ptr->rightPtr reference count = "<<ptr->rightPtr.use_count()<<std::endl;
    std::cout<<"ptr->rightPtr->parentPtr reference count = "<<ptr->rightPtr->parentPtr.lock().use_count()<<std::endl;
    std::cout<<"ptr->leftPtr->parentPtr reference count = "<<ptr->leftPtr->parentPtr.lock().use_count()<<std::endl;
    return 0;
}