class Solution
{
    public:
    //Function to return the total number of possible unique BST. 
    int numTrees(int N) 
    {
        long long  M= 1000000007;
        vector<long long>arr(N+1);
        arr[0] = 1; arr[1] = 1;
        for(int nOfNode = 2; nOfNode <= N; nOfNode++){
            for(int n = 1; n <= nOfNode; n++){
                long long l = arr[n-1],
                          r = arr[nOfNode-n];
                arr[nOfNode] = (arr[nOfNode]+ ((l*r)%M) )%M;
            }
        }
        return arr[N];
    }
};