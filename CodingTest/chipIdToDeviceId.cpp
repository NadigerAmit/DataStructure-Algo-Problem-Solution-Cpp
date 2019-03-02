#include<stdio.h>
#include<iostream>
#include<string>
#include <iomanip>
#include<stdlib.h>
#include <sstream>
#include<conio.h>

using namespace std;
long unsigned int hexToDecimal(string str) {
	std::stringstream stream; 
	string y;
	stream << str;
	stream >> hex >> y;
	return strtol(y.c_str(),NULL,16);
}
long unsigned int ChipIdToDeviceId(string chipId) {
	int count = 0;
	string last8HexDigitStr;
	for (std::string::reverse_iterator rit=chipId.rbegin(); rit!=chipId.rend(); ++rit) {
		if(count>=8) {
            break;
		}
		//string temp = *rit;
		last8HexDigitStr = *rit+last8HexDigitStr;
		count++;
	}
//	cout<< "last8HexDigitStr = "<<last8HexDigitStr<<endl;
	long unsigned int last8HexDigitnum = hexToDecimal(last8HexDigitStr);
	//cout<< "last8HexDigitnum = "<<last8HexDigitnum<<endl;
	return last8HexDigitnum+strtol("80000000",NULL,16)+1;
}
int main() {
	string chipId;
	printf("\n Enter chip ID\n");
	cin>>chipId;
	long unsigned int deviceId = ChipIdToDeviceId(chipId);
	cout<<endl<<"DeviceId = "<<deviceId<<endl;
	getch();
	return 0;
}
