#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>	
using namespace std;


typedef struct node {
	int data;
	struct node* left;
	struct node*right;
}node_t;

node_t* getNode(int data) {
	node_t* pnode = (node_t*) malloc(sizeof(node_t));
	if(pnode!= NULL) {
		pnode->left = NULL;
		pnode->right = NULL;
		pnode->data = data;
	}
	return pnode;
}
void insert(node_t** root,int data) {
	if(root == NULL) return;
	if(*root==NULL){
		*root = getNode(data);
		return ;
	}
	if((*root)->data >=data) insert(&(*root)->left,data);
	else insert(&(*root)->right,data);
}


int heghtOfTree(node_t* root) {
	if(root == NULL) return 0;
	int leftHeight = 1+heghtOfTree(root->left);
	int rightHeight = 1+heghtOfTree(root->right);
//	printf("\nLeftH = %d RHeight = %d",leftHeight,rightHeight);
	return (leftHeight>=rightHeight?leftHeight:rightHeight);
}
	
// Driver program 
int main() {
	int array1[8] = {76,3,101,987,2,99,7,10};
	int array2[7] = {76,3,100,987,2,99,7};
	node_t* root1 = NULL;

	for(auto val:array1) {
		insert(&root1,val);
	}
	cout<<"Height of root1 = "<<heghtOfTree(root1);
	return 0;
}