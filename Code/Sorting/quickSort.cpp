class Solution {
public:
    
    int partition(vector<int>& arr, int l, int r){
        if(l==r) return l;
        int val = arr[r], x = l;
        while(l<r){
            if(arr[l]<=val)
                swap(arr[x++], arr[l]);
            l++;
        }
        swap(arr[r], arr[x]);
        return x;
    }
    
    void quickSort(vector<int>& arr, int l, int r){
        if(l>=r) return;
        int p = partition(arr, l, r);
        quickSort(arr, l, p-1);
        quickSort(arr, p+1, r);
    }
    
    vector<int> sortArray(vector<int>& arr) {
        random_shuffle(arr.begin(), arr.end());
        quickSort(arr, 0, arr.size()-1);
        return arr;
    }
};