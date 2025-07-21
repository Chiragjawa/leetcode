class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // if(intervals.size() ==1) return intervals;
         sort(intervals.begin(), intervals.end());
        int i=0;
        vector<vector<int>> answer;
        while(i< intervals.size()){
            int start = intervals[i][0];
            int end = intervals[i][1];
             while(i + 1 < intervals.size() && intervals[i + 1][0] <= end) {
                end = max(end, intervals[i + 1][1]);
                i++;
            }
            answer.push_back({start, end});
            i++;
        }
        
        return answer;
    }
};