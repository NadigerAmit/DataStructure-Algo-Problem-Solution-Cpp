#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

/*


**************************************************************************************************
====================  https://www.thegeekstuff.com/2016/02/c-plus-plus-11/  ========================
**************************************************************************************************
*/

/*

**************************************************************************************************
========================================auto======================================================
**************************************************************************************************
*/
auto add(auto a,auto b) {
	return a+b;
}
/*
auto can't detect the referance automatically , it should be specified explicitly;
void AutoSwap(auto& x, auto& y) <= correct way to send referance
void AutoSwap(auto x, auto y)   <= calls by value 
*/
void AutoSwap(auto& x, auto& y) {
    auto z = x;
    x = y;
    y = z;
}

/*
**************************************************************************************************
====================================constexpr=====================================================
**************************************************************************************************
*/
/*
Rule: Any variable that should not change values after initialization and whose initializer is known at compile-time should be declared as constexpr.
Rule: Any variable that should not change values after initialization and whose initializer is not known at compile-time should be declared as const.
*/
auto constexpreDemo() {
	constexpr auto gravity (9.8); // ok, the value of 9.8 can be resolved at compile-time
    constexpr auto sum = 4 + 5; // ok, the value of 4 + 5 can be resolved at compile-time
 
    std::cout << "Enter your age: ";
    int age;
    std::cin >> age;
    const auto myAge = age; // not okay with constexpr , age can not be resolved at compile-time
	cout<<"\n age = "<<myAge;
}
/*
**************************************************************************************************
====================================decltype======================================================
**************************************************************************************************
*/

/*
decltype is a keyword used to query the type of an expression. 
Its primary intended use is in generic programming, where it is often difficult,  or even impossible, to express types that depend on template parameters.
*/

template <class A, class B> 
auto findMin(A a, B b) -> decltype(a < b ? a : b) 
{ 
    return (a < b) ? a : b; 
} 

int fun1() { return 10; } 
char fun2() { return 'g'; }
void decalTypeDemo() {
	decltype(fun1()) x; 
    decltype(fun2()) y; 
  
    cout << typeid(x).name() << endl; 
    cout << typeid(y).name() << endl; 
	
	auto z = 5; 
    // j will be of type int : data type of x 
    decltype(z) j = z + 5;   
  //  cout << typeid(j).name()<<endl;
	
    // This call returns 3.44 of doubale type 
    cout << findMin(4, 3.44) << endl;
	// This call returns 3 of int type 
    cout << findMin(5.4, 3) << endl; 
  
}

int main(){
	string a = "Amit";
	string b = "Nadiger";
	int c = 10;
	int d = 21;
	cout<<add(c,d)<<endl;
	cout<<add(a,b)<<endl;
	AutoSwap(c,d);
	cout<<"c= " <<c <<" d= "<<d<<endl;
	//constexpreDemo();
	decalTypeDemo();
	return 0;
}
	