#include<iostream>
using namespace std;

class DisjointSet{
	int n;
	vector<int>parent, height;
public:
	DisjointSet(int n): n(n){
		parent.resize(n);
		height.resize(n);
		for(int i = 0; i < n; i++)
			parent[i] = i;
	}
	int getParent(int node){
		if(node == parent[node])
			return node;
		parent[node] = getParent(parent[node]);
		return parent[node];
	}
	void combine(int node1, int node2){
		node1 = getParent(node1); node2 = getParent(node2);
		if(height[node1] > height[node2])
			parent[node2] = node1;
		else if(height[node1] < height[node2])
			parent[node1] = node2;
		else{
			parent[node2] = node1;
			height[node1]++;
		}
	}
	int getNoOfComponents(){
		for(int node = 0; node < n; node++)
			getParent(node);
		return unordered_set<int>(parent.begin(), parent.end()).size();
	}
};
