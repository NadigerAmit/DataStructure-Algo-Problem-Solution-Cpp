#include<stdio.h>
#include<iostream>
#include<string>
#include<algorithm>

#define CHAR_TO_INT(c) c-'a'
#define ALPHABET_SIZE 26

using namespace std;
struct Trie {
	Trie* childern[ALPHABET_SIZE];
	bool isleaf;
};

Trie* getNode() {
	Trie* pNode = new Trie;
	
	std::fill (std::begin(pNode->childern), std::end(pNode->childern), nullptr);
	
	pNode->isleaf = false;
	return pNode;
}	
void insert(Trie* pRoot, string str) {
	if(pRoot == nullptr) {
		return;
	}
	Trie* pCrawl = pRoot;
	for(auto c:str) {
		cout<<c <<"" <<CHAR_TO_INT(c) <<" " ;
		if(pCrawl->childern[CHAR_TO_INT(c)] == nullptr)
		    pCrawl->childern[CHAR_TO_INT(c)] = getNode();
		pCrawl = pCrawl->childern[CHAR_TO_INT(c)];
	}
	pCrawl->isleaf = true;	
}

bool search(Trie* pRoot, string str) {
	if(pRoot == nullptr) {
		return false;
	}
	Trie* pCrawl = pRoot;
	for(auto c:str) {
		cout<<c <<"" <<CHAR_TO_INT(c) <<" " ;
		if(pCrawl->childern[CHAR_TO_INT(c)] == nullptr) {
			return false;
		}
		pCrawl = pCrawl->childern[CHAR_TO_INT(c)];
	}
	if(pCrawl->isleaf == false) return false;
	return true;
}

bool hasChildern(Trie* pNode) {
	if(pNode == nullptr) return false;
	for(auto i =0;i<ALPHABET_SIZE;i++) {
		if(pNode->childern[i] != nullptr) return true;
	}
	return false;
}

int deleteString(Trie* pRoot, char* c) {
	if(pRoot == nullptr ) return 0;
	if(*c){
		if(pRoot->childern[CHAR_TO_INT(*c)]!=nullptr   // current character is present in the trie
		    && deleteString(&pRoot[CHAR_TO_INT(*c)],c+1)!=0 // Recurse to next character
		    && pRoot->isleaf != true) { // is not leaf node
			    if(!hasChildern(pRoot)) { // this situation is very less likly to happn i.e is not leaf and has no childern 
					delete pRoot;         // the above can happen whn leaf node is deleted , and left with intermediate nodes in recursive calls 
					pRoot = nullptr;
					return 1;
			    } else {
					return 0;
				}
		}
	}
	// here I reached till end of string .
	if(*c == '\0' && pRoot->isleaf) {
		if(!hasChildern(pRoot)) {
			delete pRoot;
		    pRoot= nullptr;
		    return 1;
		} else {
			pRoot->isleaf = false;
		}	
	} 
	return 0;
}

// driver program 
int main() {
	Trie* root = getNode();
	cout<<endl;
	insert(root,"omshreeganeshayanamah");
	insert(root,"om");
	insert(root,"omshree");
	insert(root,"omshreeganesh");
	cout<<endl;
	printf("\n Searching\n");

	printf("\nomshreeganeshayanama Is Found = %d\n",search(root,"omshreeganeshayanamah"));
	printf("\nom Is Found = %d\n",search(root,"om"));
	printf("\nomshree Is Found = %d\n",search(root,"omshree"));
	printf("\nomshreegane Is Found = %d\n",search(root,"omshreegane"));

	return 0;
}