#include<stdio.h>
#include<iostream>

class FunctorDemo {  // This functor object .
    public:
    int operator()(int x,int y) {  // This is functor function.
        return x+y;
    }
};

int main() {
    int x = 2,y =3;
    FunctorDemo FunctorObj;
    printf(" %d + %d = %d",x,y,FunctorObj(x,y));
    return 0;
}
