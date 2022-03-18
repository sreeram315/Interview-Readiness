#include<bits/stdc++.h>
using namespace std;

class Graph{
	int noOfNodes;
	vector<vector<int>> adjList;
public:
	Graph(int noOfNodes): noOfNodes(noOfNodes){
		adjList.resize(noOfNodes);
	}
	void addEdge(int node1, int node2){	// directed edge
		adjList[node1].push_back(node2);
	}
	void printDfs_util(int node, vector<bool>& visited){
		visited[node] = true;
		printf("%d ", node);
		for(int edgeNode: adjList[node]){
			if(!visited[edgeNode])
				printDfs_util(edgeNode, visited);
		}
	}
	void printDfs(){
		vector<bool>visited(noOfNodes, false);
		for(int node = 0; node < noOfNodes; node++){
			if(!visited[node])
				printDfs_util(node, visited);
		}
		printf("\n");
	}
};

int main(){
	Graph conn(10);
	conn.addEdge(1, 2); conn.addEdge(1, 3);
	conn.addEdge(2, 4); conn.addEdge(4, 1); 
	conn.addEdge(9, 6); conn.addEdge(1, 2);
	conn.addEdge(1, 2); conn.addEdge(1, 2);
	conn.addEdge(0, 9); conn.addEdge(4, 5);
	conn.printDfs();
}







