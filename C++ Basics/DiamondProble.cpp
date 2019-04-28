/* Diamond problem in C++ , multiple inhertance problem .
Java supportes multiple inhertance using interface and implements.
*/

#include<stdio.h>
#include<iostream>
#include<string>

using namespace std;
class Person {
	private:
	   int age;
	   string name;
	public :
	Person(int pAge,string pName):
	    age(pAge),name(pName) {;}
	    string getName() {return name;}
};

class Employe: virtual public Person {  // Virtual inheritance , counter measure agains dimond problem 
	private :
	    int empId;
	public:
	    Employe(int age,string name):
		Person(age,name),empId(1) {;}   // Person(age,name) => Base class constructor is provided , 
	                                       //but this call will be ignored in case of virtual inheritance 
	    int getEmpId() { return empId;}   
};

class Student: virtual public Person {
	private :
	    int stdId;
	public:
	    Student(int age,int stdId,string name):
			Person(age,name),stdId(stdId){}
	    int getStdId() { return stdId;}   
};

class WorkingStudent : public Employe,public Student {
	private :
	    int workingStudentId;
	public:
	    WorkingStudent(int age ,string name,int stdId):
   	        Person(age,name),Employe(age,name),Student(age,stdId,name),workingStudentId(11){;}  
	    // here should explicitly pass the parameters to base class constructor i.e Person(age,name) due to virtual inheritance.
	    int getWorkingStudentId() { return workingStudentId;}   
};

int main() {
	Person pObj(37,"Ganesh");
	Employe EObj(37,"Employee Ganesh ");
	Student Sobj(37,1,"Student Ganesh");
	WorkingStudent wObj(37,"WorkingStudent Ganesh",1);
	cout<<pObj.getName()<<endl;
	cout<<EObj.getName()<<endl;
	cout<<Sobj.getName()<<endl;
	cout<<wObj.getName();
	return 0;
}

/*
When we use virtual inheritance, we are guaranteed to get only a single instance of the common base class. 
In other words, the WorkingStudent class will have only a single instance of the Person class, 
shared by both the Student and Employe classes. By having a single instance of Person, 
we've resolved the compiler's immediate issue, the ambiguity, and the code will compile fine.

Memory Layout in Virtual Inheritance:

In order to keep track of the single instance of the Person object, the compiler will provide a virtual function table (vtable) 
for classes Student and Employe. 
When a WorkingStudent object is constructed, it creates one Person instance, a Student instance and a Employe instance.
The Student and Employe classes have a virtual pointer in their vtables that stores the offset to the Person class. 
When the Student class or the Employe class goes to access any fields of the Person, 
it uses the virtual pointer in its vtable to find the Person object and find the field in it.

Constructors and Virtual Inheritance:

Because there is only a single instance of a virtual base class that is shared by multiple classes that inherit from it, 
the constructor for a virtual base class is not called by the class that inherits from it (which is how constructors are called, 
when each class has its own copy of its parent class) 
since that would mean the constructor would run multiple times. 
Instead, the constructor is called by the constructor of the concrete class. 
In the example above, the class WorkingStudent directly calls the constructor for Person. 
If you need to pass any arguments to the Person constructor, you would do so using an initialization list, as usual:

One thing to be aware of is that if either Student or Employe attempted to invoke the Person constructor in their initialization lists,
that call will be completely skipped 
when constructing a WorkingStudent object! Be careful, as this could cause a subtle bug! 

By the way, the constructors for virtual base classes are always called before the constructors for non-virtual base classes. 
This ensures that a class inheriting from a virtual base class can be sure the virtual base class is safe to use inside 
the inheriting class's constructor. 

The destructor order in a class hierarchy with a virtual base class follows the same rules as the rest of C++: 
the destructors run in the opposite order of the constructors. In other words, the virtual base class will be the last object destroyed,
because it is the first object that is fully constructed.
*/
