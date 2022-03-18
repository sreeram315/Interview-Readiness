// https://www.geeksforgeeks.org/sum-leaf-nodes-minimum-level/

int sumOfLeafNodesAtMinLevel(Node *root){
	queue<Node*>q;
	q.push(root);
	bool foundLeaves = false;
	int sum = 0;
	while(!foundLeaves){
		int size = q.size();
		while(size--){
			Node *p = q.front();
			if(!p->left && !p->right){
				foundLeaves = true;
				sum += p->data;
			} else {
				if(p->left)
					q.push(p->left);
				if(p->right)
					q.push(p->right);
			}
		}
	}
	return sum;
}