/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        vector<pair<int, int>> inter;
        for(Interval it : intervals){
            inter.push_back({it.end, it.start});
        }
        
        sort(inter.begin(), inter.end());

        int freeTime = inter[0].first;

        for(int i=1;i<inter.size();i++){
            if(inter[i].second < freeTime){
                return false;
            }
            else{
                freeTime = inter[i].first;
            }
        }

        return true;
    }
};
