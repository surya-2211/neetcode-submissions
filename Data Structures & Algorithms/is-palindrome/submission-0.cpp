class Solution {
public:
    bool isPalin(string after, int low, int high){
        while(low<high){
            if(after[low] != after[high]){
                return false;
            }

            low++;
            high--;
        }
        return true;
    }
    bool isPalindrome(string s) {
        string after = "";
        for(char c : s){
            if(isalnum(c)){
                after += tolower(c);
            }
        }

        cout<<after;

        int n = after.length();
        if(isPalin(after, 0, n-1)){
            return true;
        }

        return false;
    }
};
