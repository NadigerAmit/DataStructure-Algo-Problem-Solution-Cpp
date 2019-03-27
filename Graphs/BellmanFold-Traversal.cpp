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
	int numOfVerticess() {return adjVector.size();}
	bool BelmanFordUtility(int src ,vector<int>& distance,vector<int>& previous);
	public:
	void addVertex(int verNum);  // Return value  == -1: operation failed , 0: already exists , 1: success 
	int addEdgeDirected(int src , int dest, int weight); // Return value  == -1: operation failed , 0: already exists , 1: success 
	int addUnDirected(int src , int dest, int weight);   //Return value  == -1: operation failed , 0: already exists , 1: success 
	void printGraph();
	int getWeightOfEdge(int src , int dest);  // 0 return , no edge exists
	int isEdgeAlreadyExists(int src,int dest);
	void BelmanFordPathFinding(int src);
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

typedef pair<int,int> iPair ; //< weight , vertexNum>

/*
1) This step initializes distances from source to all vertices as infinite and distance to source itself as 0. Create an array dist[] of size |V| with all values as infinite except dist[src] where src is source vertex.

2) This step calculates shortest distances. Do following |V|-1 times where |V| is the number of vertices in given graph.
…..a) Do following for each edge u-v
………………If dist[v] > dist[u] + weight of edge uv, then update dist[v]
………………….dist[v] = dist[u] + weight of edge uv
3) This step reports if there is a negative weight cycle in graph. Do following for each edge u-v
……If dist[v] > dist[u] + weight of edge uv, then “Graph contains negative weight cycle”

The idea of step 3 is, step 2 guarantees shortest distances if graph doesn’t contain negative weight cycle. If we iterate through all edges one more time and get a shorter path for any vertex, then there is a negative weight cycle




Algorithm:
function bellmanFord(G, S)
	for each vertex V in G
			distance[V] <- infinite
			previous[V] <- NULL
	distance[S] <- 0
	for each vertex V in G				
		for each edge (U,V) in G
			tempDistance <- distance[U] + edge_weight(U, V)
			if tempDistance < distance[V]
			   distance[V] <- tempDistance
			   previous[V] <- U

	for each edge (U,V) in G
		If distance[U] + edge_weight(U, V) < distance[V}
			Error: Negative Cycle Exists

	return distance[], previous[]
	
*/
//typedef vector<int,int> iPair; // weight,src
bool Graph::BelmanFordUtility(int src ,vector<int>& distance,vector<int>& previous) {
	bool isReaxed = false;
	distance[src] = 0;
	for(auto i:distance) cout<< i<<"  ";
	cout<<endl;
	for(auto i:adjVector) {   // do it for all the edges of all the verticess
		for(auto j: i->edgeMap) {
			int u = j.second->src;
			int v = j.second->dest;
			int weight = j.second->weight;
			if(distance[v]>distance[u]+weight) {
				previous[v] = u;
				distance[v] = distance[u]+weight;
				isReaxed = true;
			}
		}
	}
	return isReaxed;	
}
void Graph::BelmanFordPathFinding(int src) {
	int size = adjVector.size();
	vector<int> distance(size,INT_MAX);
	vector<int> previous(size,0);
	int i = 0;
	while(i<size-2) {// Repeate the n-1 times , where n  is number of edges 
		bool ret = BelmanFordUtility(src,distance,previous);
		if(ret == false) break;
		i++;
	}
	bool isNegativeCycle = BelmanFordUtility(src,distance,previous);  // relax one more time to find if there is negitive loop . If reax
	
	if(isNegativeCycle == true) {  // If releax is possiable still , then -Ve cycle exists .
		printf("\n negtative cycle exists");
	//	return;
	}
	for(auto i = 0;i<distance.size();i++) {
		cout<<i <<"-->"<<distance[i]<<" Previous = "<<previous[i]<<endl;
	}
	return ;
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

	printf("\n=================BelmanFord======================\n");
	g.BelmanFordPathFinding(src);
	
	
	return 0;
}



