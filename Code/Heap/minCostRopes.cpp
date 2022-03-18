long long minCost(long long arr[], long long n) {
    priority_queue<long long, vector<long long>, greater<long long>> pq(arr, arr+n);
    long long ans = 0;
    while(pq.size() != 1){
        long long el1 = pq.top(); pq.pop();
        long long el2 = pq.top(); pq.pop();
        ans += (el1+el2);
        pq.push(el1 + el2);
    }
    return ans;
}

// https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1/?track=P100-Heap&batchId=238