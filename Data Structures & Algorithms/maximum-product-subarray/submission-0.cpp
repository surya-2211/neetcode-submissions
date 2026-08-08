class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxProd = nums[0];
        int minProd = nums[0];
        int ans = nums[0];

        for(int i=1;i<n;i++){
            int curr = nums[i];

            int oldMin = minProd;
            int oldMax = maxProd;

            maxProd = max({curr, oldMin * curr, oldMax * curr});
            minProd = min({curr, oldMin * curr, oldMax * curr});

            ans = max(ans, maxProd);
        }

        return ans;
    }
};
