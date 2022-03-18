class Solution {
public:
    
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end());
        int i = 0, j = 1, n = arr.size();
        while(j < n){
            if(arr[i][1] >= arr[j][0])
                arr[i][1] = max(arr[i][1], arr[j][1]);
            else
                arr[++i] = arr[j];
            j++;
        }
        arr.resize(i+1);
        return arr;
    }
};