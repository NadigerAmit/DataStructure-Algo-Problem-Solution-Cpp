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

void printLinkedListinReverse(Node_t* root) {
	if(root == NULL) return;
	printLinkedListinReverse(root->next);
	printf("%d\n",root->data);
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

void printLinkedListStraigt(Node_t* root) {
	if(root == NULL) return;
	    printf("%d\n",root->data);
	return printLinkedListStraigt(root->next);
}

void convertLinkedListTodoubleLinked(Node_t* root) {
	Node_t* first = root;
	if(first->next == NULL) {
		return;
	}

	first->next->prev=first;
	convertLinkedListTodoubleLinked(first->next);
}

int main() {
	//int array[5] = {1,3,201,65,80};
	int array[9] = {1,2,3,4,5,4,3,2,1};
	int isPlandrome = 0;
	Node_t *tail = NULL;
	Node_t* root = createLinkedListWithArray(array,sizeof(array)/sizeof(array[0]),&tail);
	Node_t* tempNode = root;
	printLinkedListStraigt(tempNode);
	convertLinkedListTodoubleLinked(root);
	printf("\nPrinting the list in reverse\n");
	printLinkedListinReverse(root);
return 0;
}