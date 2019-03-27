#include<iostream>
#include<map>
#include<queue>  // for priority Queue
#include<vector>
#include<iostream>
#include<climits>     /*Used for INT_MAX*/

using namespace std;

struct Edge {
	int src;
	int dest;
	int weight;
	Edge(int s, int d, int w):
	src(s),dest(d),weight(w) {}
};

struct Vertex {
	map<int ,Edge*> edgeMap;   // dest and Node pair
	Vertex(int num) {
		;
	}
};

class  Graph{
	vector<Vertex*> adjVector;
    void dfsUtility(int src, vector<bool>&V);
	int numOfVerticess() {return adjVector.size();}
	public:
	
	void addVertex(int verNum);  // Return value  == -1: operation failed , 0: already exists , 1: success 
	int addEdgeDirected(int src , int dest, int weight); // Return value  == -1: operation failed , 0: already exists , 1: success 
	int addUnDirected(int src , int dest, int weight);   //Return value  == -1: operation failed , 0: already exists , 1: success 
	void printGraph();
	int getWeightOfEdge(int src , int dest);  // 0 return , no edge exists
	int isEdgeAlreadyExists(int src,int dest);
	void dfs(int src);
	Graph() {};
};


int Graph::addEdgeDirected(int src , int dest, int weight) {
	addVertex(src);
	addVertex(dest);
	if(getWeightOfEdge(src,dest)>0) {
		printf("\n Edge exists between %d and %d",src,dest);
		return 0;
	}
	Edge* edge = new Edge(src,dest,weight);
	adjVector[src]->edgeMap[dest] = edge;
	return 1;
}

void Graph::printGraph() {
	printf("\n Printing graph\n");
	for(auto i:adjVector) {
		if(i==nullptr) return ;
		for(auto j:i->edgeMap) {
			cout<<j.second->src <<" ---->" <<j.second->dest << "  -> Weight  " <<j.second->weight<<" "<<endl;
		}
	}
}

void Graph::addVertex(int src) {
	int vecSize= adjVector.size();
	if(vecSize>src) return ;
	for(auto i =0;i<src-vecSize;i++) {
		Vertex* ver = new Vertex(vecSize+i);
		adjVector.push_back(ver);
	}
	Vertex* ver = new Vertex(src);
	adjVector.push_back(ver);
}

int Graph::getWeightOfEdge(int src , int dest) {
    if(adjVector.size()<=src ||adjVector.size()<=dest) return 0;
	if(adjVector[src]->edgeMap.find(dest) == adjVector[src]->edgeMap.end()) return 0;
	adjVector[src]->edgeMap[dest]->weight;
	return 1;
}


void Graph::dfsUtility(int src, vector<bool>&V) {
	//for(auto i:V) cout<<i<<" ";
	cout<<src <<"  ";
	V[src] = true;
	for(auto i:adjVector[src]->edgeMap) {
		if(V[i.first] == false ) {
			dfsUtility(i.first,V);
		}
	}		
	
}

void Graph::dfs(int src) {
	vector<bool> visited(adjVector.size(),false);
	dfsUtility(src,visited);
}


int main() {
	Graph g;
	int src = 0;

	g.addEdgeDirected(0, 1, 4); 
	//g.addEdgeDirected(0, 3, 2); 
    g.addEdgeDirected(0, 7, 9); 
    g.addEdgeDirected(1, 2, 8); 
    g.addEdgeDirected(1, 7, 11); 
    g.addEdgeDirected(2, 3, 1); 
    g.addEdgeDirected(2, 8, 4); 
	g.addEdgeDirected(3, 8, 2); 
	g.addEdgeDirected(2, 7, 7); 
    g.addEdgeDirected(2, 5, 4); 
    g.addEdgeDirected(3, 4, 9);	
    g.addEdgeDirected(3, 5, 14); 
	g.addEdgeDirected(3, 7, 3); 
    g.addEdgeDirected(4, 5, 10); 
    g.addEdgeDirected(5, 6, 2);
	g.addEdgeDirected(5, 3, 2);
    g.addEdgeDirected(6, 7, 1);
    g.addEdgeDirected(6, 1, 1);	
    g.addEdgeDirected(6, 8, 6); 
    g.addEdgeDirected(7, 8, 8); 
	g.addEdgeDirected(7, 1, 8); 

	printf("\n=================Dfs ======================\n");
	g.dfs(src);
		
	return 0;
}



