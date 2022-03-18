class Solution
{
    public:
    vector<vector<int>> ans;
    vector<int>temp;
    
    void util(vector<int> arr, int n, int i){
        ans.push_back(temp);
        if(i == n) return;
        for(int j = i; j < n; j++){
            if(j==i || arr[j]!=arr[j-1]){
                temp.push_back(arr[j]);
                util(arr, n, j+1);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<int> > AllSubsets(vector<int> arr, int n) {
        sort(arr.begin(), arr.end());
        util(arr, n, 0);
        return ans;
    }
};