class Solution {
public:
    
    void merge(vector<int>& arr, int l, int mid, int r){
        int n = r-l+1, ind = 0, i1 = l, i2 = mid+1;
        vector<int>temp(n);
        while(ind != n){
            if(arr[i1] < arr[i2]){
                temp[ind++] = arr[i1++];
                if(i1==mid+1) arr[--i1] = INT_MAX;
            }else{
                temp[ind++] = arr[i2++];
                if(i2==r+1) arr[--i2] = INT_MAX;
            }
        }
        for(int i = 0; i < n; i++)
            arr[l+i] = temp[i];
    }
    
    void mergeSort(vector<int>& arr, int l, int r){
        if(l>=r) return;
        int mid = (l+r)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
    
    vector<int> sortArray(vector<int>& arr) {
        mergeSort(arr, 0, arr.size()-1);
        return arr;
    }
};















