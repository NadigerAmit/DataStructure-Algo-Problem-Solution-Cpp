/*
Static Cast
1. static_cast can perform conversions between pointers to related classes, not only from the derived class to its base, but also from a base class to its derived. 
2. This ensures that at least the classes are compatible if the proper object is converted, but no safety check is performed 
   during runtime to check if the object being converted is in fact a full object of the destination type. 
3. It is up to the programmer to ensure that the conversion is safe. 
4. Overhead of the type-safety checks of dynamic_cast is avoidedin case of static_cast.
5.  static_cast performs a tight type checking and dont allow private and protected base class to be casted to derived class
*/
#include<iostream>
#include<stdio.h>
using namespace std;
class Base { 
    virtual void fun() {} 
};

class Derived: public Base {
    int a; 
};

class Derived1: protected Base {
    int a; 
};
int main () {
    
  try {
    Base * pba = new Derived;
    Base * pbb = new Base;
    Derived * pd = nullptr;
    Derived1 * pd1 = nullptr;
    int *ptr = nullptr;

    pd = static_cast<Derived*>(pba);  //  derived to derived // Success.
    if (pd== nullptr) {
        cout << "Null pointer on first type-cast" << endl;
    } else {
        cout << "static_cast from derived to base is success " << endl;
    }

    pd = static_cast<Derived*>(pbb);  // base to derived // Success. 
    if (pd==nullptr) {
        cout << "Null pointer on second type-cast" << endl;
    } else {
        cout << "static_cast from base to derived is success " << endl;
    }
    
   // pd1 = static_cast<Derived1*>(pbb);  // base to derived Fails with static cast for privatly or protected inherited base class. // Compiler error 
    pd1 = (Derived1*)pbb;   // base to derived without static_cast success for privatly and proted inheritance. 
    if (pd==nullptr) {
        cout << "static_cast from base to privatly inherited derived is fail" << endl;
    } else {
        cout << "static_cast from base to privatly inherited derived is success " << endl;
    }
    /*
    ptr = static_cast<int*>(pbb);  // base to int* // Fails 
    if (ptr==nullptr) {
        cout << "Null pointer on third type-cast" << endl;
    } else {
        cout << "static_cast from base to integer pointer is success " << endl;
    }
    */

  } catch (exception& e) {cout << "Exception: " << e.what();}
  return 0;
}