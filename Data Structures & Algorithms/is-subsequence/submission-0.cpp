class Solution {
public:
    bool isSubsequence(string s, string t) {
        int l = 0, j = 0;

        while(l < s.length() && j < t.length()){
            if(s[l] == t[j]){
                l++;
            }

            j++;
        }

        return l == s.length();
    }
};