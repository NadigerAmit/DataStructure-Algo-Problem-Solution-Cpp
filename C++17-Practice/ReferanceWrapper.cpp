// This code copied from some post in linkedin , this is not my origional code and explain:
/*
std::reference_wrapper is a class template that wraps a reference in a copyable, assignable object.
It is frequently used as a mechanism to store references inside standard containers (like std::vector) which cannot normally hold references.

Specifically, std::reference_wrapper is a CopyConstructible and CopyAssignable wrapper around a reference to object or reference to function of type T. 
Instances of std::reference_wrapper are objects (they can be copied or stored in containers) but they are implicitly convertible to T&, 
so that they can be used as arguments with the functions that take the underlying type by reference.

If the stored reference is Callable, std::reference_wrapper is callable with the same arguments.

Helper functions std::ref and std::cref are often used to generate std::reference_wrapper objects.

std::reference_wrapper is also used to pass objects by reference to std::bind, the constructor of std::thread, or the helper functions std::make_pair and std::make_tuple.

std::reference_wrapper is guaranteed to be TriviallyCopyable.

(since C++17)
T may be an incomplete type.

(since C++20)

*/
#include <iostream>
#include <vector>
#include <functional> //Needed for reference_wrapper
using namespace std;


//Defined sample class with just a single int type data member and no deep copy required.
//This is just for demonstration purpose.
//Also class member functions are defined inline just for demo purpose.
class clsTest
{
    public:
        clsTest() = default;
        clsTest(int iData) : m_intData(iData) {cout << "Object Created\n";}
        clsTest(const clsTest& obj) {m_intData = obj.m_intData;cout << "Object Copied\n";}
        ~clsTest() {cout << "Object Destroyed\n";}
        int getValue() {return m_intData;}
        void setValue(int iData) {m_intData = iData;}
    private:
        int m_intData;
};


//Just we need to modify all the objects in vector
void updateData(vector<reference_wrapper<clsTest>>& v)
{
   for(auto elem : v)
   {


       elem.get().setValue(elem.get().getValue()*10);//mutliplying value by 10
   }
}


int main() 
{
   //Vector of class object
   vector<reference_wrapper<clsTest>> v;
    
   //create a class object
   clsTest obj(9);
  
   //Object is added to vector
   v.push_back(obj);
   
   //Print value of object member
   cout << obj.getValue() << endl;
   
   //modify objects
   updateData(v);
   
   //Print value of object member
   cout << obj.getValue() << endl;
   
   return 0;
}
/*
Output:
Object Created
9
90
Object Destroyed
*/

/*
Need / Importance :

Suppose a class object creation is very costly involving resource management. Due to this, we need to have deep copy defined in copy constructor and copy assignment operator.

If need of the hour is to have vector of objects from such class, we must have to define it like vector<T>. Here, T is nothing but class / struct type.

#include <iostream>
#include <vector>
using namespace std;


//Defined sample class with just a single int type data member and no deep copy required.
//This is just for demonstration purpose.
//Also class member functions are defined inline just for demo purpose.
class clsTest
{
    public:
        clsTest() = default;
        clsTest(int iData) : m_intData(iData) {cout << "Object Created\n";}
        clsTest(const clsTest& obj) {m_intData = obj.m_intData;cout << "Object Copied\n";}
        ~clsTest() {cout << "Object Destroyed\n";}
        int getValue() {return m_intData;}
        void setValue(int iData) {m_intData = iData;}
    private:
        int m_intData;
};


//Just we need to modify all the objects in vector
void updateData(vector<clsTest>& v)
{
   for(auto elem : v)
   {
       elem.setValue(elem.getValue()*10);//mutliplying value by 10
   }
}


int main() 
{
   //Vector of class object
   vector<clsTest> v;
    
   //create a class object
   clsTest obj(9);
  
   //Object is added to vector
   v.push_back(obj);
   
   //Print value of object member
   cout << obj.getValue() << endl;
   
   //modify objects
   updateData(v);
   
   //Print value of object member
   cout << obj.getValue() << endl;
   
   return 0;
      
  
}
If we observe output of above code, it will be something like below:

Object Created
Object Copied
9
Object Copied
Object Destroyed
9
Object Destroyed
Object Destroyed
Observe that there are unnecessary copies of object is getting created. 
Another important point to notice is value printed from object during second cout statement. 
It is still 9 even though we had passed vector as reference.

If we could have added reference into vector, it will be great. But But But..... vector<T&> is compile time error for C++ . Vector class need assignable objects, and reference being non assignable (it can only be initialized), vector<T&> is not valid.


Solution :

std::reference_wrapper is the life saver here as it is like a reference kind of behavior and still satisfy the criteria of assignable. Let's look at a code snippet of modified version of code.

#include <iostream>
#include <vector>
#include <functional> //Needed for reference_wrapper
using namespace std;


//Defined sample class with just a single int type data member and no deep copy required.
//This is just for demonstration purpose.
//Also class member functions are defined inline just for demo purpose.
class clsTest
{
    public:
        clsTest() = default;
        clsTest(int iData) : m_intData(iData) {cout << "Object Created\n";}
        clsTest(const clsTest& obj) {m_intData = obj.m_intData;cout << "Object Copied\n";}
        ~clsTest() {cout << "Object Destroyed\n";}
        int getValue() {return m_intData;}
        void setValue(int iData) {m_intData = iData;}
    private:
        int m_intData;
};


//Just we need to modify all the objects in vector
void updateData(vector<reference_wrapper<clsTest>>& v)
{
   for(auto elem : v)
   {


       elem.get().setValue(elem.get().getValue()*10);//mutliplying value by 10
   }
}


int main() 
{
   //Vector of class object
   vector<reference_wrapper<clsTest>> v;
    
   //create a class object
   clsTest obj(9);
  
   //Object is added to vector
   v.push_back(obj);
   
   //Print value of object member
   cout << obj.getValue() << endl;
   
   //modify objects
   updateData(v);
   
   //Print value of object member
   cout << obj.getValue() << endl;
   
   return 0;
      
 
}
Please note that we need to include functional for reference_wrapper class. Also observe get() method used into updateData() method.

Output of the above code is as below:

Object Created
9
90
Object Destroyed
Our both the problem got solved by reference_wrapper. 
Please note that unnecessary copies of objects can be eliminated by using emplace_back instead of push_back on vector<T>.
*/
