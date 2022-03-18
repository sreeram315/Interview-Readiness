class Solution {
public:
    
    bool isPossible(long limit, vector<int>& weights, int days){
        int i = 0, n = weights.size(), val = 0;
        while(i<n && days!=0){
            while(i<n && val+weights[i]<=limit)
                val += weights[i++];
            days--;
            val = 0;
        }
        return (i==n);
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        long l   = *min_element(weights.begin(), weights.end()),
             r   =  accumulate(weights.begin(), weights.end(), 0L),
             ans =  INT_MAX;
        while(l <= r){
            long mid = l+(r-l)/2;
            if(isPossible(mid, weights, days)){
                ans = min(ans, mid);
                r   = mid-1;
            }
            else{
                l   = mid+1;
            }
        }
        return ans;
    }
};