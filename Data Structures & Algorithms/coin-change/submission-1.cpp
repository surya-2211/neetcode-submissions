class Solution {
public:
    int solve(int ind, vector<int>& coins, int target, vector<vector<int>>& dp){
        if(ind == 0){
            if(target % coins[0] == 0) return target/coins[0];
            else return INT_MAX;
        }
        if(dp[ind][target] != -1) return dp[ind][target];

        int notTake = solve(ind-1, coins, target, dp);
        int take = INT_MAX;
        if(coins[ind] <= target){
            int res = solve(ind, coins, target - coins[ind], dp);
            if(res != INT_MAX){
                take = 1 + res;
            }
        }

        return dp[ind][target] = min(notTake, take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int ans = solve(n-1, coins, amount, dp);

        if(ans == INT_MAX){
            return -1;
        }

        return ans;
    }
};
