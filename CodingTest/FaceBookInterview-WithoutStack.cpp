#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
/*
Balance a string with parentheses. "a(b)" -> "a(b)"; "(((((" -> ""; "(()())" -> "(()())"; ")ab(()" -> "ab()";
*/

string ForewardBalance(string str) {
    int count = 0;
    int i = 0;
    int len = str.length();
    while(i<len) {
        if(str[i] == ')' && count <= 0 ) {
            str.erase(i,1);
        } else if(str[i] == '(') {
            count++;
        } else if(str[i] == ')') {
            count--;
        }
        i++;
    }
    return str;
}

string ReverseBalance(string str) {
     int count = 0;
     int i = str.length()-1;
     int len = str.length();
    
    while(i>=0) {
        if(str[i] == '(' && count <= 0 ) {
            str.erase(i,1);
        } else if(str[i] == ')') {
            count++;
        } else if(str[i] == '(') {
            count--;
        }
        i--;
    }
    return str;
}
string balance(string str) {
    return ReverseBalance(ForewardBalance(str));
}

int main() {
//  printf("\nIs String Balanced = %s\n",balance("(((a)(b)[[{()}]()))]").c_str());
//    printf("\nBalance tsring %s\n",balance(")()(((a))(").c_str());
//    printf("\nBalance tsring %s\n",balance(")))(a[(()(((").c_str());
     printf("\nBalance tsring %s\n",balance(")ab(()").c_str());
    return 0;
}
