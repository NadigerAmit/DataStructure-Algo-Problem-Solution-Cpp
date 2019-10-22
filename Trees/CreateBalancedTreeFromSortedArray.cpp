// Hello 
#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef struct node{
	struct node* left;
	struct node* right;
	struct node* next; // this is for linked list;
	int data;
}node_t;

node_t* getNode(int data) {
	node_t* tNode = new node_t;
	if(tNode==NULL) return NULL;
	tNode->data = data;
	tNode->left = NULL;
	tNode->right = NULL;
	tNode->next = NULL;
	return tNode;
}

void serachInsertinBst(node_t** root,int data) {
	if(root == NULL) return ;
	if(*root == NULL) {
		*root = getNode(data);
		return ;
	}
	if(data>(*root)->data) {
		serachInsertinBst(&(*root)->right,data);
	} else {
		serachInsertinBst(&(*root)->left,data);
	}
}
void printInOrder(node_t* root) {
	if(root == NULL) return;
	printInOrder(root->left);
	cout<<root->data<<endl;
	printInOrder(root->right);
}

void createBSTfromSortedArray(vector<int> array,int start,int end,node_t** root) {
	if(start>end) {
		printf(" =>retrun");
		return;
	}
	int mid = (start+end)/2;
	printf(" Mid = %d \n",array[mid]);
	
	serachInsertinBst(root,array[mid]);
	createBSTfromSortedArray(array,start,mid-1,root);
	createBSTfromSortedArray(array,mid+1,end,root);
}

 struct bstNode{
	node_t* node;
	int level;
	bstNode(node_t* pNode,int ilevel):
	node(pNode),
	level(ilevel) {}
};


void printBfs(node* root) {
	if(root == NULL) return;
	queue<bstNode*> Q;
	int currentLevel = 0;
	Q.push(new bstNode(root,currentLevel));
	printf("\n***********************Current Level =>%d +++++++++++++++++++++++++++++\n",currentLevel);
	while(!Q.empty()) {
		bstNode* QbstIns = Q.front();
		if(currentLevel!=QbstIns->level) {
			currentLevel++;
			printf("\n***********************Current Level =>%d +++++++++++++++++++++++++++++\n",currentLevel);
		}
		cout<< "," << QbstIns->node->data;
		Q.pop(); // remove front element
		if(QbstIns->node->left)
		Q.push(new bstNode(QbstIns->node->left,QbstIns->level+1));
	    if(QbstIns->node->right)
		Q.push(new bstNode(QbstIns->node->right,QbstIns->level+1));
		delete QbstIns;
	}
}
void printLinkedList(node_t* root) {
	while(root) {
		printf("\n %d ,",root->data);
		root= root->next;
	}
	
}
//Driver program 
int main() {
	vector<int> array = {1,2,3,4,5,6,7,8,9,10,11,12,13,14};
	//vector<int> array = {1,2,3,4,5};
	node_t* root = NULL;
	createBSTfromSortedArray(array,0,array.size()-1,&root);
	printBfs(root);
	printf("\nPrinting in DFS\n");
	printInOrder(root);
	return 0;
}