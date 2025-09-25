class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end()); 
        int ans = 0;
        int i = 0;  
        int j = 1;
        int n = intervals.size();

        while (i < n && j < n) {
            if (intervals[i][1] > intervals[j][0]) {
                ans++;
                if (intervals[i][1] > intervals[j][1]) {
                    i = j;
                }
                j++;
            } else {
                i = j;
                j++;
            }
        }
        return ans;
    }
};
