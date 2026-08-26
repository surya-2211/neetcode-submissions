class Solution {
public:
    int func(int ind, vector<int>& cost, vector<int>& dp){
        if(ind == 0 || ind == 1) return 0;
        if(dp[ind] != -1) return dp[ind];

        return dp[ind] = min(func(ind-1, cost, dp) + cost[ind-1], func(ind-2, cost, dp) + cost[ind-2]);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1, -1);
        return func(n, cost, dp);
    }
};
