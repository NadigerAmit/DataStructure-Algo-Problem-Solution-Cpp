
/*
problem :
This problem was asked by Dropbox.

Spreadsheets often use this alphabetical encoding for its columns: "A", "B", "C", ..., "AA", "AB", ..., "ZZ", "AAA", "AAB", ....

Given a column number, return its alphabetical column id. For example, given 1, return "A". Given 27, return "AA".

Solution:

Lets Observe the 3 sequences as below :

A B C...Z
AA AB AC...AZ
BA BB BC...BZ

Value for BZ will be 78.
Now given 78 as input, how do we calculate column name as BZ is question.
We divide 78 by 26, with remainder as 0 and quotient as 3.
For 0, we have Z.
For 3, it should be C but correct encoding is B, right ?
So, though BZ lies in the third sequence, the prefx is B not C, because in the first sequence, you can think it as having no prefix or may be think of 0 as prefix in first sequence.

So, in the three sequences prefix goes like 0 (no character), 1 (A), 2 (B).

That is why, whenever we have remainder as zero, we make the quotient as q-1.

Ex; 2
Example:
n = 700
Remainder (n%26) is 24. So we put ‘X’ in output string and n becomes n/26 which is 26.
Remainder (26%26) is 0. So we put ‘Z’ in output string and n becomes n/26 -1 which is 0.

*/
#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
#define ALPHABET_SZ 26  // since english has 26 chars.

using namespace std;
string columnNumToColumnName(int num) {
    string str ; // to store the string equivalant.
    int rem = 0;
    while(num>0) {
       rem =  num % ALPHABET_SZ; // find the reminder.
       if(rem == 0) {   // If remainder is 0, then a 'Z' must be there in output 
           str = 'Z'+str;
           num = (num/ALPHABET_SZ)-1;
       } else {
           char c = (rem-1)+'A';
           str = c+str;
           num = num/ALPHABET_SZ;
       }
    }
    return str;
}

int main() {
    cout<<26<<" <=column Name = " <<columnNumToColumnName(26)<<endl;
    cout<<29<<" <=column Name = " <<columnNumToColumnName(29)<<endl;
    cout<<300<<" <=column Name = " <<columnNumToColumnName(300)<<endl;
    cout<<705<<" <=column Name = " <<columnNumToColumnName(705)<<endl;
    cout<<702<<" <=column Name = " <<columnNumToColumnName(702)<<endl;
    cout<<376549<<702<<" <=column Name = " <<columnNumToColumnName(376549)<<endl;
     cout<<700<<" <=column Name = " <<columnNumToColumnName(700)<<endl;
    return 0;
}

/*
output :
26 <=column Name = Z
29 <=column Name = AC
300 <=column Name = KN
705 <=column Name = AAC
702 <=column Name = ZZ
376549702 <=column Name = UJZQ
700 <=column Name = ZX

*/