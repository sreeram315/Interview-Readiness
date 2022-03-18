// https://leetcode.com/problems/gas-station/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int rgas = 0, lag = 0, i = 0, ans = 0;
        while(i < gas.size()){
            rgas += gas[i];
            if(rgas >= cost[i])
                rgas = rgas-cost[i];
            else{
                lag += cost[i]-rgas;
                ans = i+1;
                rgas = 0;
            }
            i++;
        }
        printf("l=%d rgas=%d", lag, rgas);
        return (rgas>=lag) ? ans : -1;
    }
};