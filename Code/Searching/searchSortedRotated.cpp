class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n = arr.size(), l = 0, r = n-1, mid;
        while(l <= r){
            mid = (l+r)/2;
            if(arr[mid] == target)
                return mid;
            if(arr[l] < arr[mid]){
                if(mid!=0 && target <= arr[mid-1] && target >= arr[l])
                    r = mid-1;
                else
                    l = mid+1;
            }else{
                if(mid!=n-1 && target >= arr[mid+1] && target <= arr[r])
                    l = mid+1;
                else
                    r = mid-1;
            }
        }
        return -1;
    }
};