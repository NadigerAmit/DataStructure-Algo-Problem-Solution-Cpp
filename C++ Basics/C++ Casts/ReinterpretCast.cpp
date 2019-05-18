#include <stdio.h>
#include<iostream> 
using namespace std; 

// Copied from git hub;
/*
It is used to convert one pointer of another pointer of any type, no matter either the class is related to each other or not.
It does not check if the pointer type and data pointed by the pointer is same or not.
Note: This is very usefull when passing the objects via shared memory (obj to raw memory and raw memory to obj again )
*/
  
// creating structure mystruct 
struct mystruct { 
    int x; 
    int y; 
    char c; 
    bool b; 
}; 
  
int main() 
{ 
    mystruct s; 
  
    // Assigning values 
    s.x = 5; 
    s.y = 10; 
    s.c = 'a'; 
    s.b = true; 
  
    // data type must be same during casting 
    // as that of original 
  
    // converting the pointer of 's' to, 
    // pointer of int type in 'p'. 
    int* p = reinterpret_cast<int*>(&s); 
  
    cout << sizeof(s) << endl; 
  
    // printing the value currently pointed by *p 
    cout << *p << endl; 
  
    // incrementing the pointer by 1 
    p++; 
  
    // printing the next integer value 
    cout << *p << endl; 
  
    p++; 
  
    // we are casting back char * pointed 
    // by p using char *ch. 
    char* ch = reinterpret_cast<char*>(p); 
  
    // printing the character value 
    // pointed by (*ch) 
    cout << *ch << endl; 
  
    ch++; 
  
    /* since, (*ch) now points to boolean value, 
    so it is required to access the value using  
    same type conversion.so, we have used  
    data type of *n to be bool. */
  
    bool* n = reinterpret_cast<bool*>(ch); 
    cout << *n << endl; 
  
    // we can also use this line of code to 
    // print the value pointed by (*ch). 
    cout << *(reinterpret_cast<bool*>(ch)); 
  
    return 0; 
} 

/*
Op:
12
5
10
a
1
1
*/
