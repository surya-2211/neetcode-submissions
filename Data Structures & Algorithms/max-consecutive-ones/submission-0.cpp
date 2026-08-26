class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0;
        int maxCnt = 0;

        for(int num : nums){
            if(num == 1){
                cnt++;
                maxCnt = max(maxCnt, cnt);
            }else{
                cnt = 0;
            }
        }
        return maxCnt;
    }
};