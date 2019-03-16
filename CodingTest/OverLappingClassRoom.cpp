/*This problem was asked by Snapchat.

Given an array of time intervals (start, end) for classroom lectures (possibly overlapping), find the minimum number of rooms required.

For example, given [(30, 75), (0, 50), (60, 150)], you should return 2.
*/

#include<stdio.h>
#include<iostream>
#include<vector>
#include<map>
#include<list>
using namespace std;

typedef pair<int,int> iPair;
struct AvilableRooms { 
    vector<iPair> sharingClassTiming;
};

list<AvilableRooms*> roomList;  // list of rooms allocated;

bool isOverLapping(iPair First,iPair Second) {
	if(Second.first>=First.first && Second.first<First.second) return true;
	if(First.first>=Second.first && First.first<Second.second) return true;
	if(Second.second>=First.first && Second.second<First.second) return true;
	if(First.second>=Second.first && First.second<Second.second) return true;
	return false;
}

void AllocateNewRoom(iPair newClass) {
	AvilableRooms* newRoom = new AvilableRooms();
	newRoom->sharingClassTiming.push_back(newClass);
	roomList.push_back(newRoom);
}

bool canBeAccomodatedInAvilableRooms(iPair newCandidate) {
	for(auto i : roomList) {
		bool isSharingPossiable = true;
		for(auto j:i->sharingClassTiming) {
			if(isOverLapping(j,newCandidate)) {
				isSharingPossiable = false;
				break;
			}
		}
		if(isSharingPossiable == true) {
		    i->sharingClassTiming.push_back(newCandidate);
			return true;
		}
	}
	AllocateNewRoom(newCandidate);
	return false;
}



int main() {
	vector<iPair> classTiming = {make_pair(30, 75),make_pair(0, 50),make_pair(60, 150),make_pair(55, 80)};
	classTiming.push_back(make_pair(30, 75));
	classTiming.push_back(make_pair(0, 50));
	classTiming.push_back(make_pair(60, 150));
	classTiming.push_back(make_pair(55, 80));

	for(auto i:classTiming) {
		canBeAccomodatedInAvilableRooms(i);
	}
	cout<<"\n number of rooms required  = "<<roomList.size();
	return 0;
}
