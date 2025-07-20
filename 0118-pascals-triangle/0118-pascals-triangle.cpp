class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>answer;
        for(int i=0;i <numRows ;i++){
            int ans=1;
            vector<int>row;
            row.push_back(1);
            for(int j =0; j<i ;j++){
                ans = ans*(i-j);
                ans = ans/(j+1);
                row.push_back(ans);
            }
            answer.push_back(row);
    }
    return answer;
    }
};