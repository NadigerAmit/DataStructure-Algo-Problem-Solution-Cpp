#include<stdio.h>
#include<iostream>

/*
manipulates the constness of an object, either to be set or to be removed. 
const_cast is considered safer than simple type casting. It’safer in the sense that the casting won’t happen if the type of cast is not same as original object.
*/
using namespace std;

class Base {
    int a = 10;
    public :
    void Read() const {
        cout<<"Valu of a = "<<a;
        const_cast<Base*>(this)->Write(100);   // removing the constaness of this pointer.
        cout<<"Valu of a = "<<a;
    }
    void Write(int num) {
        a = num;
    }
};

void print (char * str)
{
   // str[2] = 'O';  // Although this is valid at compile time , leads to run time error or crash.
  cout <<endl<< str << endl;
}
int main() {
    Base b;
    b.Read();
    
    const char * c = "sample text";
    print ( const_cast<char *> (c) );
    
    int a1 = 40; 
    const volatile int* b1 = &a1; 
    cout << "typeid of b1 " << typeid(b1).name() << '\n';    
    int* c1 = const_cast <int *> (b1);   // const_cast can also be used to cast away volatile attribute.
    cout << "typeid of c1 " << typeid(c1).name() << '\n'; 
    return 0;
}

/*
Output:
Valu of a = 10Valu of a = 100
sample text
typeid of b1 PVKi
typeid of c1 Pi
*/

/*
PVKi = pointer to a volatile and constant integer.
Pi   = Pointer to integer.
*/