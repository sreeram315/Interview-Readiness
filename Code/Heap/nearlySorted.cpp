vector <int> nearlySorted(int arr[], int num, int k){
    priority_queue<int, vector<int>, greater<int>>pq(arr, arr+k);
    vector<int>ans;
    for(int i = k; i < num; i++){
        pq.push(arr[i]);
        ans.push_back(pq.top());
        pq.pop();
    }
    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}

// https://practice.geeksforgeeks.org/problems/nearly-sorted-1587115620/1/?track=P100-Heap&batchId=238