class Solution
{
    public:
    double fractionalKnapsack(int W, Item data[], int n) {
        double ans = 0;
        vector<pair<double, Item*>>arr(n);
        for(int i = 0; i < n; i++){
            double v = (double)data[i].value, w = (double)data[i].weight;
            arr[i] = {v/w, &data[i]};
        }
        sort(arr.begin(), arr.end(), greater<pair<double, Item*>>());
        int i = 0;
        while(i!=n && W>arr[i].second->weight){
            W   -= arr[i].second->weight;
            ans += arr[i].second->value;
            i++;
        }
        if(W > 0 && i!=n)
            ans += (arr[i].first)*W;
        return ans;
    }    
};