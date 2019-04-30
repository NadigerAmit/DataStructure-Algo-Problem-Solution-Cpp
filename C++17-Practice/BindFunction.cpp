/*
 =====> std::bind <=====
 It makes the code readablity more easy and less code.
std::bind is a Standard Function Objects that acts as a Functional Adaptor 
i.e. it takes a function as input and returns a new function Object as an output with with one or more of the arguments of passed function bound or rearranged.

std::bind takes a function as its first parameter and then that function’s argument as its parameter.

Return : std::bind returns a function object. In above examples we have either save this new function object in auto variable or used it directly.
*/

#include <memory>
#include <functional>
#include <iostream>
#include <algorithm>
 
using namespace std::placeholders;
 
 
int add(int first, int second)
{
	return first + second;
}
 
bool divisible(int num , int den)
{
	if(num % den == 0)
		return true;
	return false;
 
}
int approach_1()
{
	int arr[10] = {1,20,13,4,5,6,10,28,19,15};
	int count = 0;
	for(int i = 0; i < sizeof(arr)/sizeof(int); i++)
	{
		if(divisible(arr[i], 5))
			count++;
	}
	return count;
 
}
 
int approach_2()
{
	int arr[10] = {1,20,13,4,5,6,10,28,19,15};
	return std::count_if(arr, arr + sizeof(arr)/sizeof(int) , std::bind(&divisible, _1, 5));
 
}


 
int main()
{
	int x = add(4,5);
	// Will return 9
 
	// What if we want to fix the first argument
	auto new_add_func = std::bind(&add, 12, _1);
 
	x = new_add_func(5);
	// Will return 17
 
	std::cout<<x<<std::endl;
         /*
           std::bind took the first parameter a function i.e. &add and then its arguments as _1 & _2 as his own arguments.
         */
	auto mod_add_func = std::bind(&add, _2, _1);
 
	x = mod_add_func(12, 15);
	// Will return 27
	std::cout<<x<<std::endl;
 
	std::function<int (int) > mod_add_funcObj = std::bind(&add, 20, _1);
	x = mod_add_funcObj(15);
	// Will return 35
 
	std::cout<<x<<std::endl;
 
	std::cout<<approach_1()<<std::endl;
 
	std::cout<<approach_2()<<std::endl;
	return 0;
}
