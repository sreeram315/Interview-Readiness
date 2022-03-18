class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	
	int minSwaps(vector<int>&nums) {
	    int n = nums.size(), ans = 0, count;
	    if(!n) return 0;
	    vector<bool>vis(n, false);
	    vector<int>s(nums.begin(), nums.end());
	    sort(s.begin(), s.end());
	    unordered_map<int, int>mp;
	    for(int i = 0; i < n; i++) mp[s[i]] = i;
	    	
	    for(int i = 0; i < n; i++){
	        if(vis[i]) continue;
	        if(nums[i]==s[i]) continue;
	        count = 0;
	        int ind = i;
	        while(!vis[ind]){
	            vis[ind] = true;
	            ind = mp[nums[ind]];
	            count++;
	        }
	        ans += (count-1);
	       // printf("%d: count=%d\n", i, count);
	    }
	    return ans;
	}
};
// https://practice.geeksforgeeks.org/problems/minimum-swaps/1/?track=P100-Graph&batchId=238