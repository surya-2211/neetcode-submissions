class Solution {
public:
    bool checkPalin(string& s, int low, int high){
        while(low < high){
            if(s[low] != s[high]) return false;

            low++;
            high--;
        }

        return true;
    }
    bool validPalindrome(string s) {
        int n = s.length();
        int low = 0, high = n-1;
        int cnt = 0;
        while(low < high){
            if(s[low] == s[high]){
                low++;
                high--;
            }
            else{
                return checkPalin(s, low+1, high) || checkPalin(s,low,high-1);
            }
        }

        return true;
    }
};