#include<stdio.h>
#include<iostream>
#include<string>
#include<stack>
using namespace std;
/*
Balance a string with parentheses. "a(b)" -> "a(b)"; "(((((" -> ""; "(()())" -> "(()())"; ")ab(()" -> "ab()";
*/

bool checkForewardCharacterMatch(char topOfStack,char topOfString) {
    switch(topOfString) {
        case ')':
            if(topOfStack == '(') return true;
            break;
        case ']':
            if(topOfStack == '[') return true;
            break;
        case '}':
            if(topOfStack == '{') return true;
            break;
    }
    return false;
}
bool checkReverseCharacterMatch(char topOfStack,char topOfString) {
    switch(topOfString) {
        case '(':
            if(topOfStack == ')') return true;
            break;
        case '[':
            if(topOfStack == ']') return true;
            break;
        case '{':
        if(topOfStack == '}') return true;
            break;
    }
    return false;
}
bool isBalanced(string str) {
    if(str.length()<=0) return false;
    stack<char> charStack;
    int i = 0,strLen;
    strLen = str.length();
    charStack.push(str[i++]);
    while(!charStack.empty()) {
        if(i>=str.length()) break;
        switch(str[i]) {
            case '(':
            case '{':
            case '[':
                charStack.push(str[i]);
        //      printf("\nPushing %c\n",str[i]);
                break;
            case ')':
            case ']':
            case '}':
            {
                char topOfStack = charStack.top();
                bool isValid = checkForewardCharacterMatch(topOfStack,str[i]);
        //      printf("\ntopOfString  %c  topOfStack = %c isValid = %d\n",str[i],topOfStack,isValid);
                if(!isValid) return false;
                charStack.pop();
            }
                break;
            default:
                break;
        }
        i++;
    }
    if(!charStack.empty() || i<strLen){
        return false;
    }
    return true;
}
string forewardBalance(string str)  {
    if(str.length()<=0) return str;
    printf("\n Input String = %s\n",str.c_str());
    stack<char> charStack;
    int i = 0,strLen;
    strLen = str.length();
    while(i<strLen) {   // iterate till full string lenghth is covered
        bool isCharErased = false;
        switch(str[i]) {
            case '(':
            case '{':
            case '[':
                charStack.push(str[i]);
                printf("\nPushing %c\n",str[i]);
                break;
            case ')':
            case ']':
            case '}':
            {
                bool isValid = false;
                if(!charStack.empty()) {
                    char topOfStack = charStack.top();
                    isValid = checkForewardCharacterMatch(topOfStack,str[i]);
                    printf("\ntopOfString  %c  topOfStack = %c isValid = %d\n",str[i],topOfStack,isValid);
                    charStack.pop();
                } else {
                    //printf("\nStack is empty str[%d] = %c\n",i,str[i]);
                }
            
                if(!isValid) {
                    str.erase(i,1);  // delete the unmathing or invalid character.
                    isCharErased = true; 
                }
            }
            break;
            default:
            break;
        }
        // During foreward traversing , if the char is deleted from the string , 
        // we dont need to increament  the counter , since next element becomes the current element.
        if(isCharErased == false) {
            i++;
        }
    }
    return str;
}
string reversedBalance(string str)  {
    if(str.length()<=0) return str;
    stack<char> charStack;
    int i =str.length()-1;
    while(i>=0) {
        switch(str[i]) {
            case ')':
            case '}':
            case ']':
                charStack.push(str[i]);
            //  printf("\nPushing %c\n",str[i]);
                break;
            case '(':
            case '{':
            case '[':
            {
                bool isValid = false;
                if(!charStack.empty()) {
                    char topOfStack = charStack.top();
                    isValid = checkReverseCharacterMatch(topOfStack,str[i]);
                //  printf("\ntopOfString  %c  topOfStack = %c isValid = %d\n",str[i],topOfStack,isValid);
                    charStack.pop();
                } else {
                    //printf("\nStack is empty str[%d] = %c\n",i,str[i]);
                }
                if(!isValid) {
                    str.erase(i,1);
                }
            }
            break;
            default:
                break;
        }
        i--;
    }
    return str;
}

string balance(string str) {
    string forStr = forewardBalance(str);
    printf("\nForeward string = %s\n",forStr.c_str());
    string RevStr = reversedBalance(forStr);
    //printf("\nReverse string = %s\n",RevStr.c_str());
    return RevStr;
    //return forStr;
}

int main() {
//  printf("\nIs String Balanced = %s\n",balance("(((a)(b)[[{()}]()))]").c_str());
//    printf("\nBalance tsring %s\n",balance(")()(((a))(").c_str());
    printf("\nBalance tsring %s\n",balance(")))(a[(()(((").c_str());
    return 0;
}