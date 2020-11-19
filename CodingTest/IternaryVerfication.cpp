#include<stdio.h>
#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<list>
#include<queue>
//#include<priority_queue>

using namespace std;
/* Google interview :
Given an array A, where A[i] = j denotes the fact that player j finished the race before player i, and for the winner of race let's  say player k, A[k]=-1.  
You need to print the order of the positions of players after race finishes

Follow up: What if the data (array A) got courrupted, how will you take care of that. Return  -1 if there data is courrupted and order of player otherwise.
*/
/*
Given an unordered list of flights taken by someone, each represented as (origin, destination) pairs, and a starting airport, 
compute the person's itinerary. If no such itinerary exists, return null. If there are multiple possible itineraries, 
return the lexicographically smallest one. All flights must be used in the itinerary.

For example, given the list of flights [('SFO', 'HKO'), ('YYZ', 'SFO'), ('YUL', 'YYZ'), ('HKO', 'ORD')] and starting airport 'YUL', you should return the list ['YUL', 'YYZ', 'SFO', 'HKO', 'ORD'].

Given the list of flights [('SFO', 'COM'), ('COM', 'YYZ')] and starting airport 'COM', you should return null.

Given the list of flights [('A', 'B'), ('A', 'C'), ('B', 'C'), ('C', 'A')] and starting airport 'A', you should return the list ['A', 'B', 'C', 'A', 'C'] 
even though ['A', 'C', 'A', 'B', 'C'] is also a valid itinerary. However, the first one is lexicographically smaller.
*/

vector<string> airportNameVec;

typedef pair<string,string> sPair;
using namespace std;
struct Edge {
	int src;
	int dest;
	int weight;
	Edge(int s,int d,int w):
	src(s),dest(d),weight(w){;}
};

struct Node {
	string portName; // airportName
	map<int,Edge*> edgeMap; // destination , Edge
	Node(){;}
	Node(string str):portName(str) {;}
};

class Graph {
	private :
		vector<Node*> adjVertexVector;
		vector<Edge*> edgeVector;
		void addVertex(int src, string str);
		bool isEdgeExists(int src ,int dest);
		void addDirectedEdge(int src,int dest,int weight);
		
	public :
		void addAirportsToItenrnery(int src);
		void addFlights(int src ,int dest, int weight);
		void printGraph();
		list<Node*> getInternaryPath(int src);
		void dijkistra(int src);
		void bfs(int src);
};

void Graph::addVertex(int src, string str) {
	int sizeOfVertex = adjVertexVector.size();
	if(sizeOfVertex>src) {
//		printf(" %d Node already prenet ", src);
		if(adjVertexVector[src]->portName.empty() == true) {
//			printf(" %s is updated \n ", str.c_str());
			adjVertexVector[src]->portName = str;
		}
		return ;
	}
	for(int i = 0;i<(src-sizeOfVertex);i++) {
		Node* node = new Node();
		adjVertexVector.push_back(node);
	}
	Node* node = new Node();
	adjVertexVector.push_back(node);
	adjVertexVector[src]->portName = str;
//	printf("%d  %s is added \n ", src,str.c_str());
}
bool Graph::isEdgeExists(int src ,int dest) {
    if(adjVertexVector[src] == nullptr || adjVertexVector[dest] == nullptr) {return false;}
    if(adjVertexVector[src]->edgeMap.find(dest) == adjVertexVector[src]->edgeMap.end()) {return false ;}
	//printf("\n Edge between %d & %d exist",src,dest);
	return true;
}
void Graph::addDirectedEdge(int src,int dest,int weight) {
	addVertex(src,airportNameVec[src]);
	addVertex(dest,airportNameVec[dest]);
	if(isEdgeExists(src,dest)) return;
	Edge* edge = new Edge(src,dest,weight);
	adjVertexVector[src]->edgeMap.insert(make_pair(dest,edge));
	edgeVector.push_back(edge);
}
void Graph::addFlights(int src ,int dest, int weight) {
	printf("\naddFlights %d-->%d  %d\n",src,dest,weight);
	addDirectedEdge(src,dest,weight);
	
}
typedef pair<int,int> iPair; // weight ,src
void Graph::dijkistra(int src) {
	priority_queue<iPair,vector<iPair>,greater<iPair>> PQ;
	int dist[adjVertexVector.size()]; // initialize each of them with infinity
	for(int i = 0;i<adjVertexVector.size();i++) {
		dist[i] = 1111111;
	}
	dist[src] = 0;
	int Prev[adjVertexVector.size()];
	Prev[src] = 0;
	PQ.push(make_pair(0,src));
	while(!PQ.empty()) {
		iPair topInst = PQ.top();
		int v = topInst.second;
		int weight = topInst.first;
		PQ.pop();
		for(auto i: adjVertexVector[v]->edgeMap) {
			printf(" edge betweem  %d &  %d",v,i.second->dest);
			if(dist[i.second->dest]>weight+i.second->weight) {
				dist[i.second->dest] =weight+i.second->weight;
				Prev[i.second->dest] = v;
				PQ.push(make_pair(dist[i.second->dest],i.second->dest));
			}
		}
	}
	for(auto i = 0;i<adjVertexVector.size();i++) {
		printf(" \n dist[%d] = %d and Prev = %d  %s ",i,dist[i],Prev[i],airportNameVec[Prev[i]].c_str());
	}
	//return path;
}

list<Node*> Graph::getInternaryPath(int src) {
	list<Node*> iternaryPath ;
	return iternaryPath;
}
void createAirportNames() {
	airportNameVec.push_back("A");
	airportNameVec.push_back("B");
	airportNameVec.push_back("C");
	airportNameVec.push_back("D");
	airportNameVec.push_back("E");
	airportNameVec.push_back("F");
	airportNameVec.push_back("G");
}

void Graph::bfs(int src) {
	vector<int> visited;
	visited.assign(adjVertexVector.size(),0);
	queue<int> Q;
	Q.push(src);
	visited[src] = 1;
	Q.push(src);
	while(!Q.empty()) {
		int top = Q.front();
		Q.pop();
		//visited[top] = 1;
		printf(" %d ",top);
		for(auto i:adjVertexVector[top]->edgeMap) {
			if(visited[i.second->dest]) {
				continue;
			}
			Q.push(i.second->dest);
			visited[i.second->dest] = 1;
		}
	}
}
void Graph::printGraph() {
	for(auto i:adjVertexVector) {
		if(i == nullptr)continue;
		for(auto j:i->edgeMap) {
			cout<<j.second->src <<"--->"<< j.second->dest <<" =>"<<j.second->weight<<endl;
		}
	}
}
int main() {
	Graph g;
	list<sPair> iterneryList;
	iterneryList.push_back(make_pair("A","B"));
	//iterneryList.push_back(make_pair("A","C"));
	iterneryList.push_back(make_pair("B","C"));
	iterneryList.push_back(make_pair("C","A"));
	//iterneryList.push_back(make_pair("A","B"));
	createAirportNames();
	g.addFlights(0,1,2);
	g.addFlights(2,3,4);
	g.addFlights(4,5,2);
	g.addFlights(3,4,1);
	g.addFlights(1,4,1);
	g.addFlights(1,2,6);
	list<Node*> result = g.getInternaryPath(1);
	g.dijkistra(0);
	printf("\nBFS \n ");
	g.bfs(0);
	return 0;
}
