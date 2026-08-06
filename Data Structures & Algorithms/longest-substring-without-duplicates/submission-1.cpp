class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastSeen(256, -1);

        int l = 0;
        int ans = 0;

        for(int r = 0;r<s.length();r++){
            if(lastSeen[s[r]] >= l){
                l = lastSeen[s[r]] + 1;
            }

            lastSeen[s[r]] = r;

            ans = max(ans, (r-l+1));
        }

        return ans;
    }
};
