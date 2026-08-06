class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int m = t.length();
        unordered_map<char, int> mpp;
        int minLen = INT_MAX;

        for(char c : t){
            mpp[c]++;
        }

        int l = 0;
        int cnt = 0;
        int sInd = -1;
        for(int r=0;r<n;r++){
            if(mpp[s[r]] > 0) cnt++;
            mpp[s[r]]--;

            while(cnt == m){
                if((r-l+1) < minLen){
                    minLen = r-l+1;
                    sInd = l;
                }

                mpp[s[l]]++;
                if(mpp[s[l]] > 0) cnt--;
                l++;
            }
        }

        return (minLen == INT_MAX) ? "" : s.substr(sInd, minLen);
    }
};
