class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int actSum = 0;
        for(int n : nums){
            actSum += n;
        }

        int totSum = 0;
        for(int i=0;i<=nums.size();i++){
            totSum += i;
        }

        return totSum - actSum;

    }
};
