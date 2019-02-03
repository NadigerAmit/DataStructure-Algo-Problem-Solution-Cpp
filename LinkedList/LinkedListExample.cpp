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

Node_t* createLinkedListWithArray(int* array,int size,Node_t **tail) {
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

bool isListCircular(Node_t* root) {
	Node_t* first = root;
	Node_t* second = root;
	while(first != NULL || first->next != NULL) {
		first=first->next->next;
		second == second->next;
		if(first == second) {
			return true;
		}
	}
	return false;
}

void printLinkedInReverse(Node_t* root) {

	if(root == NULL) {
		return;
	}
	printf("\n%d",root->data);
	return printLinkedInReverse(root->prev);
}
void printLinkedList(Node_t* root) {
	static int i = 0;
	i++;
	printf("value of i %d\n",i);
	if(i>8) return;
	if(root == NULL) return;
	    printf("%d\n",root->data);
	return printLinkedList(root->next);
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

bool isListSimilar(Node_t* firstList,Node_t* secondList) {
	if(firstList == secondList) {
		if(firstList == NULL) {
		    return true;
		}
	}
	
	bool ret = isListSimilar(firstList->next,secondList->next);
	if(ret == false) return false;
	if((firstList->data != secondList->data)) {
		return false;
	}
	return true;
}

Node_t* dupliCateList(Node_t* root,Node_t** tail) {
	//Node_t* tail = NULL;
	if(root == NULL) return NULL;
	Node_t* secondRoot= getNode(root->data);
	secondRoot->next = dupliCateList(root->next,tail);
	if(secondRoot->next != NULL) {
		secondRoot->next->prev = secondRoot;
	} else {
		*tail = secondRoot;
	}
	return secondRoot;  // Retruning head of list
	//return tail;
}

void printLinkedListinReverse(Node_t* root) {
	if(root == NULL) return;
	printLinkedListinReverse(root->next);
	printf("%d\n",root->data);
}

void reverseLinkedList(Node_t** root) {
	if(root == NULL) return;
	Node_t*first = *root;
	Node_t*second = first->next;
	Node_t*third = NULL;
	first->next = NULL;
	while(second != NULL) {
		third = second->next;
		second->next=first;
		first=second;
		second=third;
	}
	*root = first;
}

void recursiveReverseList(Node_t** root) {
	if(root == NULL || *root == NULL) return;
    Node_t* first = *root;
	Node_t* rest = first->next;
	if(rest == NULL) return;
	recursiveReverseList(&rest);
	first->next->next = first;
	first->next = NULL;
	*root = rest;
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

bool isListPalindromeBigOof1(Node_t* first,Node_t* second) {  // faster solution takes only n itertaion O(1)
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
	bool ret = isListPalindromeBigOof1(first->next,second->next->next);
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

// Driver function.
int main() {
	//int array[5] = {1,3,201,65,80};
	int array[9] = {1,2,3,4,5,4,3,2,1};
	int isPlandrome = 0;
	Node_t *tail = NULL;
	Node_t* root = createLinkedListWithArray(array,sizeof(array)/sizeof(array[0]),&tail);
	Node_t* tempNode = root;
	printLinkedListStraigt(tempNode);
	convertLinkedListTodoubleLinked(root);
	//printf("\nPrinting the list in reverse\n");
	//printLinkedInReverse(tail);
	
	//reverseLinkedList(&root);
	//recursiveReverseList(&root);
	//isPlandrome = isListPalindrome(tempNode);
	isPlandrome = isListPalindromeBigOof1(tempNode,tempNode);
	//Node_t* duplicate = dupliCateList(root,&tail);
	printf("\nisPlandrome = %d\n",isPlandrome);
	printf("\nDuplucate Lined Listin reverse\n");
	//printLinkedListStraigt(duplicate);
	
	printLinkedInReverse(tail);
	//printLinkedListinReverse(tempNode);
return 0;
}
