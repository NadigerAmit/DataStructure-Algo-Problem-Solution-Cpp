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

void printPath(node_t* root) {
	if(root == nullptr) return ;
	printf("%d\n", root->data);
	printPath(root->left);
	printPath(root->right);
}

int heghtOfTree(node_t* root) {
	if(root == NULL) return 0;
	int leftHeight = 1+heghtOfTree(root->left);
	int rightHeight = 1+heghtOfTree(root->right);
	printf("\nLeftH = %d RHeight = %d",leftHeight,rightHeight);
	return (leftHeight>=rightHeight?leftHeight:rightHeight);
}

void printPostOrder(node_t* root) {
	if(root == NULL) return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<endl;
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
	printf("\nPronting the numbers in reverse level order\n");
	printf("\n***************Current level %d*********\n",currentLevel);
	while(!S.empty()) {
			bfsQ_t* frontSnode = S.top();
		if(currentLevel != frontSnode->level){
			currentLevel = frontSnode->level;
			printf("\n***************Current level %d*********\n",currentLevel);
		}	
		cout<<" " <<frontSnode->rootNode->data;
		S.pop();
		free(frontSnode);
	}

}

bool isTreesSame(node_t* root1,node_t* root2) {
	if(root1 == root2 ) {
		if(root1 == NULL) return true;
	}
	if(root1 == NULL) return false;
	if(root2 == NULL) return false;
	if(root1->data == root2->data) {
		if(!isTreesSame(root1->left,root2->left)) return false;
		if(!isTreesSame(root1->right,root2->right)) return false;
		return true;
	}
	return false;
}

void getCopyofTree(node_t* srcRoot,node_t** destRoot) {
	if(srcRoot == NULL) return ;
	*destRoot = getNode(srcRoot->data);
	getCopyofTree(srcRoot->left,&(*destRoot)->left);
	getCopyofTree(srcRoot->right,&(*destRoot)->right);
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
	printf("\nsrcRoot->data %d destRoot->data %d",srcRoot->data,destRoot->data);
	if(srcRoot->data == destRoot->data) return true;
	else return false;
}

void iterativeInordrTraversal(node_t* root) {
	if(root == NULL) return;
	stack<node_t*> S;
	while(1) {
		while(root) {
			// push in to stack;
			S.push(root);
			root = root->left;
		}
		if(S.empty()) break;
		root = S.top();
		printf("%d\n",root->data);
		S.pop();
		root = root->right;
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
	bool istreesSame = isTreesSame(root1,root2);
	printf("\n is same tree %d",istreesSame);
	cout<<"\n isTrees Same =" <<isTreesSame << endl;
	cout<<"Height of root1"<<heghtOfTree(root1);
	
	/*
	printf("Printing the printInOder");
	int size = printInOder(root1);
	printf("\n Size of tree = %d\n ",size);
	printf("Printing the printPreOrder");
    size = printPreOrder(root1);
	printf("\n Size of tree = %d\n ",size);
	*/
	int size = printPreOrder(root1,pathVector);
	printf("\nXXXXXXXXXXXXXXXXXXXXXXX\n");
	printpathElements(pathVector);
	printf("\nXXXXXXXXXXXXXXXXXXXXXXX\n");
	printf("\n Size = %d\n ",size );
	convertToMirror(root3);
	printf("Printing in BFS of root1 ");
	//doBfs(root1);
	//printf("Printing in BFS of root3 ");
//	doBfs(root3);
	printBfsInReverseOrder(root1);
	iterativeInordrTraversal(root1);
	bool isMirror = isOneTreeMirrorOfAnother(root1,root3);
	printf("\n is root1 is mirror tree of root3 %d",isMirror);
//	isMirror = isOneTreeMissorOfAnother(root1,root2);
	printf("\n is root1 is mirror tree of root2 %d",isMirror);
	
	return 0;
}