class Solution 
{
    public:

    vector<int> JobScheduling(Job arr[], int n)  { 
        int MAX_DEADLINE = 100;
        sort(arr, arr+n, [](Job j1, Job j2){return j1.profit > j2.profit;});
        vector<int>ans(MAX_DEADLINE+1, -1);
        int count = 0, profit = 0;
        for(int i = 0; i < n; i++){
            Job p = arr[i];
            int k = p.dead;
            while(k > 0){
                if(ans[k]==-1){
                    ans[k] = p.id;
                    count++;
                    profit += p.profit;
                    break;
                }
                k--;
            }
        }
        return {count, profit};
    } 
};