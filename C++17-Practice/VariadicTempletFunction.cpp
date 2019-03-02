/*
Variadic Template is introduced in C++11. Variadic Template allows a function to take variable number of arguments of any type.
Suppose we want to create a function log() that accepts variable number of arguments of any type and prints them on console i.e.

------------------------------
log(1,4.3, "Hello");
 
log('a', "test", 78L, 5);
 
class Student;
Student obj;
 
log(3, obj);
 
etc..
-------------------------------

It means we have 2 requirements while creating log() function i.e.

1.) It should accept any type of arguments.
2.) It should accept variable number of arguments.

=======>  [With vardiac template we can define a function that accepts variable number of template parameters] i.e.
template<typename T, typename ... Args>
void log(T first, Args ... args);

Declaring a vardiac template function is easy but its definition is little tricky. We cann’t access the the passed variable number of arguments directly. 
We need to use the c++ type deduction mechanism & recursion to achieve this. Let’s define the variadic function i.e.

*/

#include <iostream>
 
// Function that accepts no parameter
// It is to break the recursion chain of vardiac template function
void log()
{
}
 
/*
 * Variadic Template Function that accepts variable number
 * of arguments of any type.
 */
template<typename T, typename ... Args>
void log(T first, Args ... args) {
 
	// Print the First Element
	std::cout<<first<<" , ";
 
	// Forward the remaining arguments
	log(args ...);
}
 
 
int main() {
 
	log(2, 3.4, "aaa","Amit");
 
	return 0;
}