#include<iostream>
#include<map>
#include<queue>  // for priority Queue
#include<vector>
#include<iostream>
#include<climits>     /*Used for INT_MAX*/

using namespace std;
/*
Dijkistra algorithm is greedy algo
    => Greedy algo means , choose the best avilable option at that point of time without thinging long term profit.
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
	void dfsUtility(int src, vector<bool>&V);
	void bfsUtility(int src,vector<bool>&V);
	bool BelmanFordUtility(int src ,vector<int>& distance,vector<int>& previous);
	int numOfVerticess() {return adjVector.size();}
	public:
	void addVertex(int verNum);  // Return value  == -1: operation failed , 0: already exists , 1: success 
	int addEdgeDirected(int src , int dest, int weight); // Return value  == -1: operation failed , 0: already exists , 1: success 
	int addUnDirected(int src , int dest, int weight);   //Return value  == -1: operation failed , 0: already exists , 1: success 
	void printGraph();
	int getWeightOfEdge(int src , int dest);  // 0 return , no edge exists
	int isEdgeAlreadyExists(int src,int dest);
	void dijkstra(int src);
	void dijkstraDebuuging(int src);
	void dfs(int src);
	void bfs(int src);
	void BelmanFordPathFinding(int src);
	Graph* TransposeOfGraph();
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
void Graph::dijkstra(int src ) {
	vector<int> distance;
	priority_queue<iPair,vector<iPair>,greater<iPair>> PQ;
	for(int i=0;i<adjVector.size();i++) distance.push_back(INT_MAX); 
	vector<int> previous;
	previous.resize(adjVector.size());
	distance[src] = 0;
	PQ.push(make_pair(0,src));
	while(!PQ.empty()) {
		iPair inst = PQ.top();
		PQ.pop();
		int u = inst.second;
		int weight = inst.first;
		for(auto i:adjVector[u]->edgeMap) {
			int v = i.second->dest;
			if(distance[v]>distance[u]+ i.second->weight) {
				distance[v] = distance[u]+ i.second->weight;
				PQ.push(make_pair(distance[v],v));
				previous[v] = u;
			}
		}
	}
    printf("\n Dijikstra Algorithm \n");
	for(int i = 0;i<distance.size();i++) {
		printf("\n %d -> %d => %d \n",i,distance[i],previous[i]);
	}
	
}

// with debug prints for understanding 
void Graph::dijkstraDebuuging(int src) {
	vector<bool> visited(adjVector.size(),false);
    vector<int> previous(adjVector.size(),0);
//	priority_queue<iPair,vector<iPair>> pq;
	
	priority_queue<iPair,vector<iPair>,greater<iPair>> pq;  // create the priority queue of <weight,Vertex>
	//queue<iPair> pq;
	vector<int> dist(adjVector.size(),INT_MAX);  // Prepare the distance table of size = number of vertex
	dist[src] = 0;                               // distance of src from src = 0, update the distance table
	pq.push(make_pair(0,src));                   // push the source vertex psir <weight,vert> in priority queue
	int s = 0;
	while(!pq.empty()) {   
         s++;	
		iPair inst = pq.top();                   // take the 1st elemnt of queue and shortest distance for this is found.
		cout<<"Top elemt  weight = " <<inst.first <<" node = "<<inst.second<<endl;
		//iPair inst = pq.front();                  
		pq.pop();                              
		int v = inst.second;                     // take the vertex number of that instance 
		printf("\n v = %d",v);
		if(v==src) {
			printf("\n src again came here \n");
		}			
	//	if(visited[v] == true) { cout<<endl<<v<< " visited \n";continue; }        // If node is already visited , no need to visit again that node and its nebhors .
	//	visited[v] = true;
		for(auto i:adjVector[v]->edgeMap) {      // visit all the nodes connected to that vertex via edge from that vertex
			int u = i.first;                     // retrive the connceted vertex 
			int weight = i.second->weight;       // retrive the wight of coonected edge with source if v .
			if(dist[u]>dist[v]+weight) {         // This is relax function , if cost of connected vertex is more then cost or parent + weight of edge
			    previous[u] = v;
				dist[u] = dist[v]+weight;        // replace the cost of the connected vertex with small value ,since this node can traversed with less cost than earleir 
				pq.push(make_pair(dist[u],u));   // push the modified cost new cost and the vertex to priority queue.
				cout<<"Pushing dist " <<dist[u] <<" node = "<<u<<endl;
			}
		}
	}
	printf("\n Shortest path in number of steps %d\n",s);
	for(auto i=0;i<dist.size();i++) {
		cout<<i<<"---"<<dist[i] <<" Pre = " <<previous[i]<<endl;
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

void Graph::bfsUtility(int src, vector<bool>&V) {
	//for(auto i:V) cout<<i<<" ";
	queue<int> Q;
    Q.push(src);
    while(!Q.empty()) {
		int ins = Q.front();
		Q.pop();
		if(V[ins] == false) {
			cout<<ins <<" ";
			V[ins] = true;
		}
		for(auto i: adjVector[ins]->edgeMap) {
			if(V[i.first] == false)
			    Q.push(i.first);
		}
    }
}

void Graph::bfs(int src) {
	vector<bool> visited(adjVector.size(),false);
	bfsUtility(src,visited);
}

/*
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
	bool isNegativeCycle = BelmanFordUtility(src,distance,previous);
	
	if(isNegativeCycle == true) {
		printf("\n negtative cycle exists");
	//	return;
	}
	for(auto i = 0;i<distance.size();i++) {
		cout<<i <<"-->"<<distance[i]<<" Previous = "<<previous[i]<<endl;
	}
	return ;
}


/*
We traverse the adjacency list and as we find a vertex v in the adjacency list of vertex u which indicates an edge from u to v in main graph, we just add an edge from v to u in the transpose graph 
i.e. add u in the adjacency list of vertex v of the new graph. Thus traversing lists of all vertices of main graph we can get the transpose graph. 
Thus the total time complexity of the algorithm is O(V+E) where V is number of vertices of graph and E is the number of edges of the graph.
*/
Graph* Graph::TransposeOfGraph() {
	printf("\n Transpose of Graph = %d",this->numOfVerticess());
	Graph* t = new Graph();
	for(auto v:this->adjVector) {
		if(v==nullptr) break;
		for(auto e:v->edgeMap) {
			printf("edge between %d --%d W(%d)\n",e.second->dest,e.second->src,e.second->weight);
			t->addEdgeDirected(e.second->dest,e.second->src,e.second->weight);
		}
	}
	return t;
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
//	g.printGraph();
//	printf("\n=================Dijkistra ======================\n");
//	g.dijkstra(src);
//	printf("\n=================Dfs ======================\n");
//	g.dfs(src);
//	printf("\n=================Bfs ======================\n");
//	g.bfs(src);

/*
	g.addEdgeDirected(0,1,-1);
	g.addEdgeDirected(0,2,4);
	g.addEdgeDirected(1,2,3);
	g.addEdgeDirected(1,3,2);
	g.addEdgeDirected(1,4,2);
	g.addEdgeDirected(1,4,2);
	g.addEdgeDirected(3,2,5);
	g.addEdgeDirected(3,1,1);
	g.addEdgeDirected(4,3,-3);
*/


	printf("\n=================Dijkstra======================\n");
	g.dijkstraDebuuging(src);
	printf("\n=================BelmanFord======================\n");
	g.BelmanFordPathFinding(src);
	
	
	return 0;
}



