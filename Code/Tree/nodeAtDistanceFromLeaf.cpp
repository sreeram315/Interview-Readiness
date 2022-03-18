int ans;
vector<Node*>arr;
unordered_set<Node*>ms;
void util(Node *p, int k){
    if(!p) return;
    arr.push_back(p);
        int n = arr.size();
    if(!p->left && !p->right && ((n-k-1)>=0) ){
        ms.insert(arr[n-k-1]);
    }
    util(p->left, k);
    util(p->right, k);
    arr.pop_back();
}


//Function to return count of nodes at a given distance from leaf nodes.
int printKDistantfromLeaf(Node* root, int k) {
	arr.clear(); ms.clear();
	ans = 0;
	util(root, k);
	return ms.size();
}