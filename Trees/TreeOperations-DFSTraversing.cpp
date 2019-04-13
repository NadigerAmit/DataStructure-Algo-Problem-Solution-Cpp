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


int printInOder(node_t* root) {
	static int size = 0;
	if(root == NULL) return size;;
	printInOder(root->left);
	cout<<root->data<<endl;
	size++;
	printInOder(root->right);
	return size;
}

void printPreOrder(node_t* root) {
	if(root == NULL) return;
	cout<<root->data<<endl;
	printPreOrder(root->left);
	printPreOrder(root->right);

}


void printPostOrder(node_t* root) {
	if(root == NULL) return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<endl;
}

// Driver program 
int main() {
	int array1[8] = {76,3,101,987,2,99,7,10};
	int array2[7] = {76,3,100,987,2,99,7};
	node_t* root1 = NULL;
	for(auto val:array1) {
		insert(&root1,val);
	}

	printf("Printing the printInOder");
	printInOder(root1);
	printf("Printing the printPreOrder");	
	printPreOrder(root1);
	printf("Printing the printPostOrder");	
	printPostOrder(root1);

	return 0;
}