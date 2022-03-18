Node* constructBst(int arr[], int size) {
    int ind = 0, x, n;
    queue<Node *>q;
    unordered_map<int, pair<int, int>>mp;
    mp[arr[ind]] = {INT_MIN, INT_MAX};
    Node *p = new Node(arr[ind++]);
    q.push(p);
    while(ind < size){
        Node *p = q.front(); q.pop();
        n = p->data;
        x = arr[ind];
        if(x<n && (x>mp[n].first)){
            mp[x] = {mp[n].first, n};
            p->left = new Node(arr[ind++]);
            q.push(p->left);
        }
        if(ind==size) break;
        n = p->data;
        x = arr[ind];
        if(x>n && (x<mp[n].second)){
            mp[x] = {n, mp[n].second};
            p->right = new Node(arr[ind++]);
            q.push(p->right);
        }
    }
	return p;
}