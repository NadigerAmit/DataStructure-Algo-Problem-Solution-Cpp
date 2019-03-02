#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*
*****************************************************************************************************************************************************
================================================================
Lambda : How to capture member variables inside Lambda function
================================================================
[firstPart](secondPart) TypeYouReturn{ BodyOfLambda}(acctualParameters);

1> FirstPart is used for variable scope which will be exploited inside the lambda function. You could use more variables if have a need for that.

         Keep the following in mind when you are using this syntax for the [firstPart]:

        [] it means that you will not provide anything to give to lambda.
        [&] it is used to say that you have some references to mess with.
        [=] it is used to make the copy.
        [this] is used to the enclosing class.

    1. If we try to capture member variable directly by value or reference, then it will not work i.e.
    2. To capture the member variables inside lambda function, capture the “this” pointer by value i.e.
        Capturing this pointer inside lambda function will automatically capture all the member variables for this object inside lambda.
        Below oddCounter function capture by value 

2> secondPart is necessary for parameter list for nameless function but it could be left empty as well.
3> TypeYouReturn is used to register what type will be returned from your lambda.
4> BodyOfLambda is used for actions you wish to do, in here you will type some code that will be used to perform actions you are intended to apply in the body of this function.
5> ActualParameters are used to provide input into lambda function.
*****************************************************************************************************************************************************
*/
class OddCounter
{
	// tracks the count of odd numbers encountered
	int mCounter = 0;
public:
	int getCount()
	{
		return mCounter;
	}
	void update(std::vector<int> & vec)
	{
		// Traverse the vector and increment mCounter if element is odd
		// this is captured by value inside lambda
		std::for_each(vec.begin(), vec.end(), [this](int element){
			if(element % 2)
				mCounter++;                            // <==  Accessing member variable from outer scope
		});
	}
};

 
int main() {
    int arr[] = { 1, 2, 3, 4, 5 };
 
    int mul = 5;
	
	auto lambda = [](auto x, auto y) {return x + y;};
	printf("\n Lambda = ");
	cout<<lambda(3,4.5)<<endl;
 
    std::for_each(arr, arr + sizeof(arr) / sizeof(int), [&](int x) {   // [outer scope by referanve] (int x) {}
        std::cout<<x<<" ";
        // Can modify the mul inside this lambda function because
        // all outer scope elements has write access here.
            mul = 3;
        });
    std::cout << std::endl;
 
    std::for_each(arr, arr + sizeof(arr) / sizeof(int), [=](int &x) {
        x= x*mul;
        // Can not modify the mul inside this lambda function because
        // all outer scope elements has read only access here.
        // mul = 9;
		cout<< x <<" "; 
 
        });
    std::cout << std::endl;
 
    std::for_each(arr, arr + sizeof(arr) / sizeof(int), [](int x) {
 
        // No access to mul inside this lambda function because
        // all outer scope elements are not visible here.
        //std::cout<<mul<<" ";
        });
    std::cout << std::endl;
	
	/*
	=========================================== Below code for invoking the lamda function for capturring the member variable inside the lamda function
	*/
	std::vector<int> vec = {12,3,2,1,8,9,0,2,3,9,7};
 
	OddCounter counterObj;
 
	//Passing the vector to OddCounter object
	counterObj.update(vec);
 
	int count = counterObj.getCount();
 
	std::cout<<"Counter = "<<count<<std::endl;
 
}
/*
Lambda functions are a kind of anonymous functions in C++. These are mainly used as callbacks in C++. Lambda function is like a normal function i.e.

You can pass arguments to it
It can return the result
But it doesn’t have any name. Its mainly used when we have to create very small functions to pass as a callback to an another API.
*/