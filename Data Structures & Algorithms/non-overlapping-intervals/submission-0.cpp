class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        vector<pair<int, int>> inter;
        for(auto it : intervals){
            inter.push_back({it[1], it[0]});
        }

        sort(inter.begin(), inter.end());
        int cnt = 1;
        int freeTime = inter[0].first;

        for(int i=1;i<inter.size();i++){
            if(inter[i].second >= freeTime){
                cnt++;
                freeTime = inter[i].first;
            }
        }

        return n - cnt;
    }
};
