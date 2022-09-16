
/*
Below code gives you Fibonacci value at compile time, without even creating class or function.
This the beauty of  Variable Template you can now templatise the variable also since C++14
*/
#include<stdio.h>
#include<iostream>

using namespace std;


// Example 1 below 
template <class T>
constexpr T pi = T(3.1415926535897932385L); // variable template

// Example 2 below 

template <uint32_t val> // template specilaization
constexpr auto fib = fib<val - 1> + fib<val - 2>;

template <> // template specilaization
constexpr auto fib<0> = 0;

template <> // template specilaization
constexpr auto fib<1> = 1;

int main() {
	
	// Example 1 below 
	cout <<" ** Example 1 below ** " << endl; 
	cout <<"Pi value in float = "<< pi<float> << endl; // 3.14159
    cout <<"Pi value in int = "<< pi<int> << endl<<endl; 
	
	//// Example 2 below 
	cout <<" ** Example 2 below  ** " << endl; 
	cout <<"Fib of 1 = "<< fib<1> << endl;    // 1
	cout <<"Fib of 2 = "<< fib<2> << endl;    // 1
	cout <<"Fib of 3 = "<< fib<3> << endl;    // 2
    cout <<"Fib of 4 = "<< fib<4> << endl;    // 3
	cout <<"Fib of 5 = "<< fib<5> << endl;    // 5
	cout <<"Fib of 6 = "<< fib<6> << endl;    // 8
	cout <<"Fib of 7 = "<< fib<7> << endl;    // 13
	cout <<"Fib of 8 = "<< fib<8> << endl;    // 21
	cout <<"Fib of 9 = "<< fib<9> << endl;    // 34
	cout <<"Fib of 10 = "<< fib<10> << endl;  // 55
	 return 0;
}

