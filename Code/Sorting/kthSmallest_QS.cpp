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
    /*
    3 1 2 4 6 5
          x     l
    let x be point such that all to the right of it(inclusive) are greater than pivot
    from l to r-1:
    - if val is greater - pass
    - if val is less or equal - inc(x) swap()
    inc l
    */
    
    
    int findKthSmallest(vector<int>& arr, int k) {
        int n = arr.size(), l = 0, r = n-1;
        while(true){
            int p = partition(arr, l, r);
            if(p == k)
                return arr[p];
            else if(p > k)
                r = p-1;
            else
                l = p+1;
        }
        return -1;
    }
};