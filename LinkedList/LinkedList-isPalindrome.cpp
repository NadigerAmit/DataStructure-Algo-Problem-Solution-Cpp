#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct node {
    int data;
	struct node* next;
	struct node* prev;
} Node_t;

Node_t* getNode(int data) {
    Node_t *ptr = (Node_t*)malloc(sizeof(Node_t));
	assert(ptr != NULL);
	ptr->data = data;
	ptr->prev = NULL;
	ptr->next = NULL;
	return ptr;
}

static Node_t* createLinkedListWithArray(int* array,int size,Node_t **tail) {
    if(size <=0) return NULL;
	Node_t* root = NULL;
	Node_t* tempNode = NULL;
    for(int i=0;i<size;i++) {
		if(i == 0) {
		    tempNode = getNode(array[i]);
			root = tempNode;
		} else {
			tempNode->next = getNode(array[i]);
			tempNode = tempNode->next;
		}
		*tail = tempNode;
	}
    return root;
}

class list {
	private: int size;
	private: Node_t* head;
	private: Node_t* tail;
	private: static Node_t* getNode(int data);
	private: static Node_t* createLinkedListWithArray1(int* array,int size,Node_t **tail);
	public :
	list(int* array,int numofElements);
	list();
	int sizeOfList();
	void insert(int data);
};
list::list() {
	size = 0;
	head = tail = NULL;
}
list::list(int* array, int numofElements) {
	size = numofElements;
	head = createLinkedListWithArray(array,numofElements,&tail);
	if(size <= 0) return;
	int i = 0;
	head = getNode(array[i]);
	Node_t* tempNode = head;
	for(i =1;i<size;i++) {
		tempNode->next = getNode(array[i]);
		tempNode = tempNode->next;
	}
	tail = tempNode;
}

Node_t* list::createLinkedListWithArray1(int* array,int size,Node_t **tail) {
    if(size <=0) return NULL;
	Node_t* root = NULL;
	Node_t* tempNode = NULL;
    for(int i=0;i<size;i++) {
		if(i == 0) {
		    tempNode = getNode(array[i]);
			root = tempNode;
		} else {
			tempNode->next = getNode(array[i]);
			tempNode = tempNode->next;
		}
		*tail = tempNode;
	}
    return root;
}

int list::sizeOfList() {
	return size;
}

Node_t* list::getNode(int data) {
    Node_t *ptr = (Node_t*)malloc(sizeof(Node_t));
	assert(ptr != NULL);
	ptr->data = data;
	ptr->prev = NULL;
	ptr->next = NULL;
	return ptr;
}

// 1 is true 
// 0 is false

bool isListPalindrome(Node_t* root) {
	static Node_t* first = root ;
	if(root == NULL || first->next == NULL) return true;
    int ret = isListPalindrome(root->next);
	if(ret == false) return false;
	printf("%d  --> %d\n",first->data,root->data);
	if(root->data != first->data) return false; //List is not palindrome;
	first=first->next;
	return true;
}

bool isListPalindromeFasterSoln(Node_t* first,Node_t* second) {  // faster solution takes only n itertaion O(1)
	static int parityOfNodes ;
	static bool isFirstNode = true;
    if(second == NULL) {  
		parityOfNodes = 0; // even // dont care of case where there is only 1 node.
		if(isFirstNode == true) {
			return false;
		}
		return true;  
	}
	isFirstNode = false;
	if(second->next == NULL) {
		parityOfNodes = 1; // odd // dont care of case where there is only 1 node.
		return true;
	}
	static int j=0;
	static Node_t* third = NULL;
	bool ret = isListPalindromeFasterSoln(first->next,second->next->next);
	if(ret == false) return false;
	if(j == 0) {
		printf("\nparityOfNodes = %d",parityOfNodes);
		j++;
		if(parityOfNodes == 0) { // even number of nodes
		    printf("\n even MiddleNode = %d",first->data);
			third = first;
		} else {  // odd number of nodes
			third = first->next;
		    printf("\nMiddleNode = %d\n",third->data);
		}
	}
	third = third->next;
	if(third == NULL) return true;
	if(third->data != first->data) {
		printf("forewardData = %d  BackWardData  = %d",third->data,first->data);
		return false;
	}
	printf("\noutside forewardData = %d  BackWardData  = %d",third->data,first->data);
	return true;	
}
void printLinkedListStraigt(Node_t* root) {
	if(root == NULL) return;
	    printf("%d\n",root->data);
	return printLinkedListStraigt(root->next);
}


int main() {
	//int array[5] = {1,3,201,65,80};
	int array[9] = {1,2,3,4,5,4,3,2,1};
	int isPlandrome = 0;
	Node_t *tail = NULL;
	Node_t* root = createLinkedListWithArray(array,sizeof(array)/sizeof(array[0]),&tail);
	Node_t* tempNode = root;
	printLinkedListStraigt(root);
	isPlandrome = isListPalindromeFasterSoln(tempNode,tempNode);
	printf("\nisPlandrome = %d\n",isPlandrome);
return 0;
}