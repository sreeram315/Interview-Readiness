vector<vector<int> > stockBuySell(vector<int> a, int n){
    int i = 0;
    vector<vector<int> > ans;
    while(i < n-1){
        if(a[i] < a[i+1]){
            vector<int>temp;
            temp.push_back(i);
            while(i<n-1 && a[i]<=a[i+1])
                i++;
            temp.push_back(i);
            ans.push_back(temp);
        }
        i++;
    }
    return ans;
}
//https://practice.geeksforgeeks.org/problems/stock-buy-and-sell-1587115621/1/?track=P100-Arrays&batchId=238