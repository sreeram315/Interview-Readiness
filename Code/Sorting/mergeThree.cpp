

vector<int> mergeThree(vector<int>& a, vector<int>& b, vector<int>& c)  { 
    int i = 0, j = 0, k = 0;
    int l = a.size(), m = b.size(), n = c.size();
    int size = l+m+n;
    vector<int>ans(size); int ind = 0;
    while(ind != size){
        if(a[i]<b[j] && a[i]<c[k]){
            ans[ind++] = a[i++];
            if(i==l) a[--i] = INT_MAX;
        }else if(b[j] < c[k]){
            ans[ind++] = b[j++];
            if(j==m) b[--j] = INT_MAX;
        }else{
            ans[ind++] = c[k++];
            if(k==n) c[--k] = INT_MAX;
        }
    }
    return ans;
} 