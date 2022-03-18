#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *left, *right;
	Node (int data): data(data), left(nullptr), right(nullptr){}
};

class BST{
	Node *root = nullptr;
public:
	BST(){};
	// insert
	Node* insert(Node *node, int val){
		if(!node){
			Node *newNode = new Node(val);
			return newNode;
		}
		if(node->data > val)
			node->left = insert(node->left, val);
		else if(node->data < val)
			node->right = insert(node->right, val);
		return node;
	}
	void insert(int val){
		root = insert(root, val);
	}	
	// delete
	Node* deleteNode(Node *node, int val){
		if(!node) return nullptr;
		if(node->data > val)
			node->left = deleteNode(node->left, val);
		else if(node->data < val)
			node->right = deleteNode(node->right, val);
		if(node->data == val){
			if(!node->left || !node->right)
				return (node->left) ? (node->left) : (node->right);
			Node *succ = node->right, *succParent = node->right;
			while(succ->left){
				succParent = succ;
				succ = succ->left;
			}
			node->data = succ->data;
			if(succ == succParent)
				node->right = succ->right;
			else
				succParent->left = succ->right;
			free(succ);
		}
		return node;
	}
	void deleteNode(int num){
		root = deleteNode(root, num);
	}
	void printInorder(){
		printf("Inorder: ");
		stack<Node*>st;
		Node *p = root;
		while(p || !st.empty()){
			while(p){
				st.push(p);
				p = p->left;
			}
			p = st.top(); st.pop();
			printf("%d ", p->data);
			p = p->right;
		}
		cout << endl;
	}
	void printLevelOrder(){
		printf("Level Order:\n");
		queue<Node*>q;
		q.push(root);
		while(!q.empty()){
			int size = q.size();
			while(size--){
				Node *p = q.front(); q.pop();
				printf("%d ", p->data);
				if(p->left)
					q.push(p->left);
				if(p->right)
					q.push(p->right);
			}
			cout << endl;
		}
		cout << endl;
	}
};

int main(){
	BST myTree;
	myTree.insert(15); myTree.insert(7); myTree.insert(21); myTree.insert(1); myTree.insert(9); myTree.insert(22); myTree.insert(20);
	myTree.printInorder();
	myTree.printLevelOrder();
	myTree.deleteNode(2);
	// myTree.deleteNode(21);
	myTree.printLevelOrder();
	cout << endl;
}