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

void printpathElements(vector<int> pathEle) {
	printf("\n new path\n");
	for(auto val:pathEle) {
		cout<<val<<" ";
	}
	cout<<endl;
}
// Below code also print the path elements. 
vector<int> pathVector;
int  printPreOrder(node_t* root,vector<int> pathVector) {
	static int size = 0;
	if(root == NULL) {
		return size;
	}
	if(root->left == NULL && root->right == NULL) {
		pathVector.push_back(root->data);
		printpathElements(pathVector);
		// can calculate the sum also 
	}
	size++;
	//cout<<root->data<<endl;
	pathVector.push_back(root->data);
	printPreOrder(root->left,pathVector);
	printPreOrder(root->right,pathVector);
	return size;
}

// Driver program 
int main() {
	int array1[8] = {76,3,101,987,2,99,7,10};
	int array2[7] = {76,3,100,987,2,99,7};
	node_t* root1 = NULL;
	for(auto val:array1) {
		insert(&root1,val);
	}
	
	int size = printPreOrder(root1,pathVector);
	printf("\nXXXXXXXXXXXXXXXXXXXXXXX\n");
	printpathElements(pathVector);
	printf("\nXXXXXXXXXXXXXXXXXXXXXXX\n");
	printf("\n Size = %d\n ",size );

	
	return 0;
}