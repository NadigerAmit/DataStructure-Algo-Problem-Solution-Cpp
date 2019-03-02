#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

class User
{
 
	int id;
	std::string name;
public:
	User(int userId, std::string userName) : id(userId), name(userName)
	{}
 
	// Copy Constructor is deleted
	User(const User & obj) = delete;
	// Assignment operator is deleted
	User & operator = (const User & obj) = delete;
 
	void display()
	{
		std::cout<<id << " ::: "<<name<<std::endl;
	}
 
	// Deleting a constructor that accepts a double as ID to prevent narrowing conversion
	User(double userId, std::string userName) = delete ;
 
	// Deleting a constructor that accepts a double as ID to prevent invalid type conversion
	User(char userId, std::string userName) = delete ;
 
	// Delete the new function to prevent object creation on heap
	void * operator new (size_t) = delete;
 
};
 
 // Delete specific template specialisation
template <typename T>
class ComplexNumber
{
	T x;
	T y;
public:
	ComplexNumber(T a, T b) : x(a) , y(b)
	{}
	void display()
	{
		std::cout<<x << " + i"<<y<<std::endl;
	}
        
	ComplexNumber(char a, char b) = delete;   // <==  Deleted template specialisation 
        // Deleted template specialisation  
	ComplexNumber(double a, double b) = delete;  // <== Deleted template specialisation 
};
 
int main()
{
	User userObj(3, "John");
	userObj.display();
 
	// Can not copy User object as copy constructor is deleted
	//User obj = userObj;
 
 
	/*
	 * Creating User objects with double or char as ID will cause compile time error
	 *
	User obj4(5.5, "Riti");
 
	obj4.display();
 
	User obj5('a', "Riti");
 
	obj5.display();
	 */
 
	// Can not create object on heap as new operater is deleted
 
	//User * ptr = new User(1, "Riti");
 
	return 0;
}