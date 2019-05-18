
/*
Dynamic casts :

1. dynamic_cast can be used only with pointers and references to objects. 
2. Its purpose is to ensure that the result of the type conversion is a valid complete object of the requested class.
3. dynamic_cast is always successful when we cast a class to one of its base classes:
4. When dynamic_cast cannot cast a pointer because it is not a complete object of the required class (from base to derived )
5. If dynamic_cast is used to convert to a reference type and the conversion is not possible, an exception of type bad_cast is thrown instead.
*/

// dynamic_cast
#include<stdio.h>
#include <iostream>
#include <exception>
using namespace std;

class Base { 
    virtual void fun() {} 
};

class Derived: public Base {
    int a; 
};

int main () {
  try {
    Base * pba = new Derived;
    Base * pbb = new Base;
    Derived * pd = nullptr;

    pd = dynamic_cast<Derived*>(pba);  //  derived to derived // Success.
    if (pd== nullptr) {
        cout << "Null pointer on first type-cast" << endl;
    }

    pd = dynamic_cast<Derived*>(pbb);  // base to derived // Fails 
    if (pd==nullptr) {
        cout << "Null pointer on second type-cast" << endl;
    }

  } catch (exception& e) {cout << "Exception: " << e.what();}
  return 0;
}

// Op: Null pointer on second type-cast
/*
Note : dynamic_cast requires the Run-Time Type Information (RTTI) to keep track of dynamic types. 
Some compilers support this feature as an option which is disabled by default. 
This must be enabled for runtime type checking using dynamic_cast to work properly.

In The above example :
when their respective type-castings are performed using dynamic_cast, pba is pointing to a full object of class Derived,
 whereas pbb is pointing to an object of class CBase, which is an incomplete object of class Derived.


*/