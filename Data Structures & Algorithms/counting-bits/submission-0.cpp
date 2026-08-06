class Solution {
public:
    int numberOfBits(int n){
        int cnt = 0;
        while(n){
            n = n & n-1;
            cnt++;
        }
        return cnt;
    }
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0;i<=n;i++){
            int bits = numberOfBits(i);
            ans.push_back(bits);
        }

        return ans;
    }
};
