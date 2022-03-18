class Solution
{
    public:
    struct Item{
        int w, v;
        double wv;
        Item(int w, int v, double wv){
            this->w = w;
            this->v = v;
            this->wv = wv;
        }
    };
    
    static bool comp(Item *i1, Item *i2){
        return i1->wv > i2->wv;
    }
    
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<Item*>rat(n);
       for(int i = 0; i < n; i++)
            rat[i] = new Item(wt[i], val[i], (double)val[i]/(double)wt[i]);
        vector<vector<int>> arr(W+1, vector<int>(n+1));
        for(int i = 0; i <= W; i++){
            for(int j = 0; j <= n; j++){
                if(i==0 || j==0)
                    arr[i][j] = 0;
                else{
                    arr[i][j] = arr[i][j-1];
                    int ind = (i-(rat[j-1]->w));
                    if( ind >= 0)
                        arr[i][j] = max(arr[i][j], rat[j-1]->v + arr[ind][j-1]);
                }
            }
        }
        return arr[W][n];
    }
};