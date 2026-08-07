class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int curr = 0;

        for(int x : nums){
            curr += x;

            maxSum = max(maxSum, curr);

            if(curr < 0){
                curr = 0;
            }
        }

        return maxSum;
    }
};
