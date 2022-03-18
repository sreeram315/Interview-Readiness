class Solution{
    public:
        int minimumjumps(int arr[],int n){
            if(!arr[0]) return -1;
            int mr = arr[0], j = 1, s = arr[0];
            for(int i = 1; i < n-1; i++){
                s--;
                mr = max(mr, i+arr[i]);
                if(s==0){
                    if(mr <= i) return -1;
                    j++;
                    s = mr-i;
                }
            }
            return j;
        }
};