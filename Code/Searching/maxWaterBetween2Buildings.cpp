int maxWater(int arr[], int n)  { 
    int l = 0, r = n-1, ans = -1;
    while(l<r){
        ans = max(min(arr[l], arr[r])*(r-l-1), ans);
        if(arr[l] < arr[r]) l++;
        else r--;
    }
    return ans;
} 

// https://practice.geeksforgeeks.org/problems/maximum-water-between-two-buildings/1/?track=P100-Searching&batchId=238