struct comp {
    bool operator()(Node *p, Node *q) {
        return p->data > q->data;
    }
};

Node * mergeKLists(Node *arr[], int K)
{
    priority_queue<Node*, vector<Node*>, comp>pq(arr, arr+K);
    Node *ans = new Node(0), *temp = ans;
    while(!pq.empty()){
        auto p = pq.top(); pq.pop();
        ans->next = p;
        ans = ans->next;
        if(p->next)
            pq.push(p->next);
    }
    return temp->next;
}