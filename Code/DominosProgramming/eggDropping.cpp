// RECC
int eggDrop(int e, int f)  {
    if(e==1 || f<=1) return f;
    int ans = INT_MAX;
    for(int x = 1; x <= f; x++){
        ans = min(  ans, 
                    max(eggDrop(e-1, f-x), eggDrop(e, x-1))+1
                );
    }
    return ans;
}


// DP with binary search
int eggDrop(int e, int f)  {
    int val;
    vector<vector<int>>arr(E+1, vector<int>(F+1));
    for(int e = 0; e <= E; e++){
        for(int f = 0; f <= F; f++){
            val = INT_MAX;
            if(f<=1 || e==1)
                val = f;
            else if(e==0)
                val = INT_MAX;
            else{
                int l = 0, r = f;
                while(l<=r){
                    int mid = (r+l)/2;
                    int left = arr[e-1][mid-1],
                        right = arr[e][f-mid];
                    if(left > right)
                        r = mid-1;
                    else
                        l = mid+1;
                    val = min(val, max(left, right)+1);
                }
            }
            arr[e][f] = val;
        }
    }
    return arr[E][F];
}