/*
Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

Given two singly linked lists that intersect at some point, find the intersecting node. The lists are non-cyclical.

For example, given A = 3 -> 7 -> 8 -> 10 and B = 99 -> 1 -> 8 -> 10, return the node with value 8.

In this example, assume nodes with the same value are the exact same node objects.

Do this in O(M + N) time (where M and N are the lengths of the lists) and constant space.
*/
#include<stdio.h>
#include<iostream>
#include<map>
#include<vector>

using namespace std;

typedef struct node {
	struct node* next;
	int data ;
} Node_t;

int findIntersectingPoint(Node_t* root1, Node_t* root2) {
	if(root1 == nullptr || root2 == nullptr) return -1;
	map<int,Node_t*> nodeMap;
	while(root1 != nullptr) {
		nodeMap[root1->data] = root1;
		root1 = root1->next;
	}
	
	while(root2 != nullptr) {
		if(nodeMap.find(root2->data) != nodeMap.end()) {
			return root2->data;
		}
		root2 = root2->next;
	}
	return -1;
}

Node_t* getNode(int data ){
	Node_t* root = nullptr;
	root = new Node_t;
	root->data = data;
	root->next = nullptr;
	return root;
}

Node_t* createListFromArray(vector<int> array){
	Node_t* root = nullptr;
	Node_t* initialNode = nullptr;
	
	
	for(auto i = array.begin();i!= array.end();i++) {
		if(i == array.begin()) {
			root = getNode(*i);
			initialNode = root;
		}
		root->next = getNode(*i);
		root = root->next;
	}
	return initialNode;
}


int main() {
	vector<int> arr1 = {1,3,4,5,6,7,8};
	vector<int> arr2 = {10,11,12,135,7,17,18};
	Node_t* list1 = createListFromArray(arr1);
	Node_t* list2 = createListFromArray(arr2);
	int intersectionPoint = findIntersectingPoint(list1,list2);
	cout<<endl<<"intersection point = "<<intersectionPoint<<endl;
	
	return 0;
}