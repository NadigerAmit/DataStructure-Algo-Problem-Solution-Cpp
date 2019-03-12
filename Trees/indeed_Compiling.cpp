// Find the leaf node with minimum cost .

//                A
//             /  |  \
//           4  10   5
//           /    |    \
//          B     C     D
//         / \    |    / \
//       6   7  10   1   5
//       /     \  |  /     \
//      E       F G H       I
//                 / \
//               2   3
//               /     \
//              J       K


//               A
//             /4 |10 \5
//           B   C    D
//          /6 \7 |10 /1 \5
//         E    F G  H    I
//                 /2 \3
//               J    K
               

#include<stdio.h> 
#include<iostream> 
#include<vector>
#include<map>
using namespace std;
struct Node;

struct Edge {
    int cost;
    Node* target;
};
struct Node {
    vector<Edge> children;
};



// analysis
// O(n) and O(1)
Node* leastWeightNode = nullptr ;
int LeastWeight = 99999;

void getLeastWieghtLeafNode(Node* root,int weight) {
    if(root == nullptr ) return ;
    if(root->children.size() == 0) { // this is leaf node.
        if(weight<LeastWeight) {
			LeastWeight = weight;
			leastWeightNode = root;
		}
        return ;
    }
    
    for(int  i = 0;i<root->children.size();i++) {
		if(weight+root->children[i]>LeastWeight) return ;
        getLeastWieghtLeafNode(root->children[i].target,weight+root->children[i].cost);
    }
    
}

map<int,Node*> weightMap;
void  getWieghtOfLeaf(Node* root,int weight) {
    if(root == nullptr ) return ;
    if(root->children.size() == 0) {
        weightMap.insert(make_pair(weight,root));
        return ;
    }
    
    for(int  i = 0;i<root->children.size();i++) {
        getWieghtOfLeaf(root->children[i].target,weight+root->children[i].cost);
    }
    
}

Node* findMinLeaf(Node* root) {
    // TODO
    getWieghtOfLeaf(root,0);
    auto itr = weightMap.begin();
    if(itr == weightMap.end()) return nullptr;
    return itr->second;
    
}