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

void printBfsInReverseOrder(node_t* root) {
	int currentLevel = 0;
	if(root == NULL) return;
	bfsQ_t* Qnode = getBfsNode(root,currentLevel);
	stack<bfsQ_t*> S;
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
		S.push(frontQnode); // Push it in to the stack
		Q.pop();
		if(frontQnode!= NULL && frontQnode->rootNode != NULL) {
			if(frontQnode->rootNode->left!= NULL) Q.push(getBfsNode(frontQnode->rootNode->left,frontQnode->level+1));
			if(frontQnode->rootNode->right!= NULL) Q.push(getBfsNode(frontQnode->rootNode->right,frontQnode->level+1));
		}
		//free(frontQnode);
	}
	printf("\nPrinting the numbers in reverse level order\n");
	printf("\n***************Current level %d*********\n",currentLevel);
	while(!S.empty()) {
			bfsQ_t* topSnode = S.top();
		if(currentLevel != topSnode->level){
			currentLevel = topSnode->level;
			printf("\n***************Current level %d*********\n",currentLevel);
		}	
		cout<<" " <<topSnode->rootNode->data;
		S.pop();
		free(topSnode);
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

    printf("Printing in BFS of root1 ");
	printBfsInReverseOrder(root1);
	return 0;
}
