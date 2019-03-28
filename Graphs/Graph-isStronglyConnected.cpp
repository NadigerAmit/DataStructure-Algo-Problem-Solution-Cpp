#include<iostream>
#include<map>
#include<queue>  // for priority Queue
#include<vector>
#include<iostream>
#include<climits>     /*Used for INT_MAX*/

using namespace std;

struct GraphEdges {
	int weight;
	int src ;
    int dest;
    GraphEdges(int s, int d , int w):
		weight(w),
		src(s) , 
		dest(d) {;}	
};

struct GraphNode {
	map<int,GraphEdges> edgeMap; // dest ,GraphEdges
};

struct Graph {
	private:
	    vector<GraphNode*> adjVector;
		bool isAlreadyEdgeExists(int src,int dest);
		void dfsUtility(int src, vector<bool>&V);
		Graph* TransposeOfGraph();
	public:
	    Graph(int numOfVertex);
	    void addDirectedEdge(int src , int dest , int weight);
	    void addUndirectedEdge(int src , int dest , int weight);
	    void printfGraph() ;
	    void dfs(int src);
		bool isGraphStronglyConnected();
};


Graph::Graph(int numOfVertex) {
	GraphNode* node = nullptr;
	for(int i = 0;i<numOfVertex;i++) {
		node = new GraphNode();
		adjVector.push_back(node);
	}
}


/*
 Kosaraju’s Algorithm for finding is Grph is strongly connected.

Following is Kosaraju’s DFS based simple algorithm that does two DFS traversals of graph:
1) Initialize all vertices as not visited.

2) Do a DFS traversal of graph starting from any arbitrary vertex v. If DFS traversal doesn’t visit all vertices, then return false.

3) Reverse all arcs (or find transpose or reverse of graph)

4) Mark all vertices as not-visited in reversed graph.

5) Do a DFS traversal of reversed graph starting from same vertex v (Same as step 2). If DFS traversal doesn’t visit all vertices, then return false. Otherwise return true.
*/

bool Graph::isGraphStronglyConnected() {
	int src = 0;
	vector<bool> visited(adjVector.size(),false);
	dfsUtility(src,visited);
	for(auto i:visited) {
		if(i == false) return false; // graph is not connected as there is unvisited vertex.
	}
	Graph* TransposeGrapgh = TransposeOfGraph();
	vector<bool> TransposeGraphvisited(adjVector.size(),false);
	TransposeGrapgh->dfsUtility(src,TransposeGraphvisited);
	for(auto i:TransposeGraphvisited) {
		if(i == false) return false; // graph is not connected as there is unvisited vertex.
	}
	return true;
}

void Graph::addDirectedEdge(int src , int dest , int weight) {
	if(src>adjVector.size() || dest>adjVector.size()) {
		printf("\n the src(%d) or destnation(%d) is out of range(%d)",src,dest,adjVector.size());
		return ;
	}
	if(isAlreadyEdgeExists(src,dest) == true) {
		printf("\n Edge already exists between %d %d",src,dest);
	}
	GraphEdges* edge = new GraphEdges(src,dest,weight);
	adjVector[src]->edgeMap.insert(make_pair(dest,*edge));
}
bool Graph::isAlreadyEdgeExists(int src ,int dest) {
	if(src>adjVector.size() || dest>adjVector.size()) {
		return false;
	}
	if(adjVector[src]->edgeMap.find(dest) == adjVector[src]->edgeMap.end()) {
		return false;
	}
	return true;
}

void Graph::addUndirectedEdge(int src , int dest , int weight) {
	if(src>adjVector.size() || dest>adjVector.size()) {
		printf("\n the src(%d) or destnation(%d) is out of range(%d)",src,dest,adjVector.size());
		return ;
	}
	if(isAlreadyEdgeExists(src,dest) == true) {
		printf("\n Edge already exists between %d %d",src,dest);
	}
	GraphEdges* edge = new GraphEdges(src,dest,weight);
	adjVector[src]->edgeMap.insert(make_pair(dest,*edge));
	GraphEdges* edge1 = new GraphEdges(dest,src,weight);
	adjVector[dest]->edgeMap.insert(make_pair(src,*edge1));
}

void Graph::printfGraph() {
	printf("\n printing the graph\n");
	for(auto i:adjVector) {
		
		for(auto j:i->edgeMap) {
			cout<<j.second.src <<"---->"<<j.second.dest <<"("<<j.second.weight<<")"<<endl;
		}
		cout<<endl<<endl;
	}
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

/*
We traverse the adjacency list and as we find a vertex v in the adjacency list of vertex u which indicates an edge from u to v in main graph, we just add an edge from v to u in the transpose graph 
i.e. add u in the adjacency list of vertex v of the new graph. Thus traversing lists of all vertices of main graph we can get the transpose graph. 
Thus the total time complexity of the algorithm is O(V+E) where V is number of vertices of graph and E is the number of edges of the graph.
*/
Graph* Graph::TransposeOfGraph() {
	Graph* t = new Graph(adjVector.size());
	for(auto v:this->adjVector) {
		if(v==nullptr) break;
		for(auto e:v->edgeMap) {
			printf("edge between %d --%d W(%d)\n",e.second.dest,e.second.src,e.second.weight);
			t->addDirectedEdge(e.second.dest,e.second.src,e.second.weight);
		}
	}
	return t;
}

int main() {
	Graph g(9);
	int src = 0;

	g.addDirectedEdge(0, 1, 4); 
	//g.addDirectedEdge(0, 3, 2); 
    g.addDirectedEdge(0, 7, 9); 
    g.addDirectedEdge(1, 2, 8); 
    g.addDirectedEdge(1, 7, 11); 
    g.addDirectedEdge(2, 3, 1); 
    g.addDirectedEdge(2, 8, 4); 
	g.addDirectedEdge(3, 8, 2); 
	g.addDirectedEdge(2, 7, 7); 
    g.addDirectedEdge(2, 5, 4); 
    g.addDirectedEdge(3, 4, 9);	
    g.addDirectedEdge(3, 5, 14); 
	g.addDirectedEdge(3, 7, 3); 
    g.addDirectedEdge(4, 5, 10); 
    g.addDirectedEdge(5, 6, 2);
	g.addDirectedEdge(5, 3, 2);
    g.addDirectedEdge(6, 7, 1);
    g.addDirectedEdge(6, 1, 1);	
    g.addDirectedEdge(6, 8, 6); 
    g.addDirectedEdge(7, 8, 8); 
	g.addDirectedEdge(7, 1, 8); 

	bool isGrapghConnected = g.isGraphStronglyConnected();
    if(isGrapghConnected == true) {
		printf("\n Grapgh is strongly connected.");
	} else {
		printf("\n Grapgh is not strongly connected.");
	}
	
	return 0;
}



