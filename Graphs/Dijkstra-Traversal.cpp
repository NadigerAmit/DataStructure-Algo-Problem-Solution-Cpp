#include<iostream>
#include<map>
#include<queue>  // for priority Queue
#include<vector>
#include<iostream>
#include<climits>     /*Used for INT_MAX*/

using namespace std;
/*
Dijkistra algorithm is greedy algo
    => Greedy algo means , choose the best avilable option at that point of time without thinking long term profit.
It uses priority queue to store unvisited vertices by distance from S.
Doesnt work with negetive weights .

Procedure :
	
Maintain the distance table with below columns 

Vertex     Distnace[V](distance from source to Ver V)      Parent of[V] (Previous vertex which gave Distnace[V])
:
:
:

Steps:

1. The algorithms works by keeping the shortest distance of vertex V from the source in Distance table 
2. Distance[V] holds the distance from s to v
3. The shortest distance of source to itself is 0
4. Distance[V] of all other verticess set to INFINIY to Indicate that those verticess are not yet processed.

Algorithm :

function dijkstra(G, S)
    for each vertex V in G
        distance[V] <- infinite
        previous[V] <- NULL
        If V != S, add V to Priority Queue Q
    distance[S] <- 0
	
    while Q IS NOT EMPTY
        U <- Extract MIN from Q
        for each unvisited neighbour V of U
            tempDistance <- distance[U] + edge_weight(U, V)
            if tempDistance < distance[V]
                distance[V] <- tempDistance
                previous[V] <- U
    return distance[], previous[]


RELAX (u,v,w) {
	tempDistance <- distance[U] + edge_weight(U, V)
            if tempDistance < distance[V]
                distance[V] <- tempDistance
                previous[V] <- U
	return
}

*/

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
	public:

	void addVertex(int verNum);  // Return value  == -1: operation failed , 0: already exists , 1: success 
	int addEdgeDirected(int src , int dest, int weight); // Return value  == -1: operation failed , 0: already exists , 1: success 
	int addUnDirected(int src , int dest, int weight);   //Return value  == -1: operation failed , 0: already exists , 1: success 
	void printGraph();
	int getWeightOfEdge(int src , int dest);  // 0 return , no edge exists
	int isEdgeAlreadyExists(int src,int dest);
	void dijkstra(int src);
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

// with debug prints for understanding 
void Graph::dijkstra(int src) {
	vector<bool> visited(adjVector.size(),false);
    vector<int> previous(adjVector.size(),0);

	priority_queue<iPair,vector<iPair>,greater<iPair>> pq;  // create the priority queue of <weight,Vertex>
	vector<int> dist(adjVector.size(),INT_MAX);  // Prepare the distance table of size = number of vertex
	dist[src] = 0;                               // distance of src from src = 0, update the distance table
	pq.push(make_pair(0,src));                   // push the source vertex psir <weight,vert> in priority queue
	while(!pq.empty()) {   
		iPair inst = pq.top();                   // take the 1st elemnt of queue and shortest distance for this is found.
		//iPair inst = pq.front();                  
		pq.pop();                              
		int v = inst.second;                     // take the vertex number of that instance 		
		for(auto i:adjVector[v]->edgeMap) {      // visit all the nodes connected to that vertex via edge from that vertex
			int u = i.first;                     // retrive the connceted vertex 
			int weight = i.second->weight;       // retrive the wight of coonected edge with source if v .
			if(dist[u]>dist[v]+weight) {         // This is relax function , if cost of connected vertex is more then cost or parent + weight of edge
			    previous[u] = v;
				dist[u] = dist[v]+weight;        // replace the cost of the connected vertex with small value ,since this node can traversed with less cost than earleir 
				pq.push(make_pair(dist[u],u));   // push the modified cost new cost and the vertex to priority queue.
			}
		}
	}

	for(auto i=0;i<dist.size();i++) {
		cout<<i<<"---"<<dist[i] <<" Pre = " <<previous[i]<<endl;
	}
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

	printf("\n=================Dijkstra======================\n");
	g.dijkstra(src);
	return 0;
}



