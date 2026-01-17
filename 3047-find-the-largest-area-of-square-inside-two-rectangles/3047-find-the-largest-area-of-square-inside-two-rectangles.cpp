class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        long long side = 0;
        int n = bottomLeft.size();
        for(int i =0;i<n-1;i++){
            for(int j =i+1 ;j<n;j++){
                int x1 = max(bottomLeft[i][0],bottomLeft[j][0]);
                int y1 = max(bottomLeft[i][1], bottomLeft[j][1]);
                int x2 = min(topRight[i][0], topRight[j][0]);
                int y2 = min(topRight[i][1], topRight[j][1]);
                int width = x2-x1;
                int height = y2-y1;
                if(width>0 && height>0){
                    long long currside = min(height, width);
                    side = max(side, currside);
                }
            }
        }
        return (side*side);
    }
};