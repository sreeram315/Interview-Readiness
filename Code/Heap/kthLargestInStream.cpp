    void kthLargest(int arr[], int n, int k)
    {
    	priority_queue<int, vector<int>, greater<int>>pq;
    	for(int i = 0; i < n; i++){
    	    int el = arr[i];
    	    if(pq.size() < k){
    	        pq.push(el);
    	        pq.size()==k ? printf("%d ", pq.top()) : printf("-1 ");
    	    }else{
    	        if(pq.top() < el){
    	            pq.pop();
    	            pq.push(el);
    	        }
    	        printf("%d ", pq.top());
    	    }
    	}
    }