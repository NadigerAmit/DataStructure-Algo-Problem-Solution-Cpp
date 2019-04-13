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



void convertToMirror(node_t* srcRoot) {
	if(srcRoot == NULL) return;
	convertToMirror(srcRoot->left);
	convertToMirror(srcRoot->right);
	/* swap the pointers in this node */
	node_t* tempNode = srcRoot->left;
	srcRoot->left = srcRoot->right;
	srcRoot->right = tempNode;
}

bool isOneTreeMirrorOfAnother(node_t* srcRoot,node_t* destRoot) {
	static bool ret = true;
	if(srcRoot == destRoot) {
		if(srcRoot == NULL) return true;
	}
	if(srcRoot == NULL) return false;
	if(destRoot == NULL) return false;
	if(ret == false) return false;
	if(!(ret = isOneTreeMirrorOfAnother(srcRoot->left,destRoot->right))) return false;
	if(!(ret = isOneTreeMirrorOfAnother(srcRoot->right,destRoot->left))) return false;
//	printf("\nsrcRoot->data %d destRoot->data %d",srcRoot->data,destRoot->data);
	if(srcRoot->data == destRoot->data) return true;
	else return false;
}

void getCopyofTree(node_t* srcRoot,node_t** destRoot) {
	if(srcRoot == NULL) return ;
	*destRoot = getNode(srcRoot->data);
	getCopyofTree(srcRoot->left,&(*destRoot)->left);
	getCopyofTree(srcRoot->right,&(*destRoot)->right);
}

typedef struct bfsQ{
	node_t* rootNode;
	int level;
}bfsQ_t;

bfsQ_t* getBfsNode(node_t* rootNode,int level) {
	bfsQ_t* tempQ = (bfsQ_t*)malloc(sizeof(bfsQ_t*));
	tempQ->level = level;
	tempQ->rootNode = rootNode;
	return tempQ;
}

queue<bfsQ_t*> Q;
void doBfs(node_t* root) {
	int currentLevel = 0;
	if(root == NULL) return;
	bfsQ_t* Qnode = getBfsNode(root,currentLevel);
	if(Qnode == NULL) return;
	printf("\n************* Level%d ********\n",currentLevel);
	Q.push(Qnode);
	while(!Q.empty()) {
		bfsQ_t* frontQnode = Q.front();
		if(currentLevel != frontQnode->level) {
			currentLevel++;
			printf("\n************* Level%d ********\n",currentLevel);
		}
		printf("%d ",frontQnode->rootNode->data);
		Q.pop();
		if(frontQnode!= NULL && frontQnode->rootNode != NULL) {
			if(frontQnode->rootNode->left!= NULL) Q.push(getBfsNode(frontQnode->rootNode->left,frontQnode->level+1));
			if(frontQnode->rootNode->right!= NULL) Q.push(getBfsNode(frontQnode->rootNode->right,frontQnode->level+1));
		}
		free(frontQnode);
	}
}
	
// Driver program 
int main() {
	int array1[8] = {76,3,101,987,2,99,7,10};
	int array2[7] = {76,3,100,987,2,99,7};
	node_t* root1 = NULL;
	node_t* root2 = NULL;
	node_t* root3 = NULL;
	for(auto val:array1) {
		insert(&root1,val);
	}
	for(auto val:array2) {
		insert(&root2,val);
	}
	getCopyofTree(root1,&root3);

	convertToMirror(root3);
	printf("Printing in BFS of root1 ");
	doBfs(root1);
	printf("Printing in BFS of MirrorTree ");
	doBfs(root3);
	
	bool isMirror = isOneTreeMirrorOfAnother(root1,root3);
	printf("\n is root1 is mirror tree of root3 %d",isMirror);
	isMirror = isOneTreeMirrorOfAnother(root1,root2);
	printf("\n is root1 is mirror tree of root2 %d",isMirror);
	
	return 0;
}