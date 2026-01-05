class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int cnt=0;
        int cnt2=0;
        int mini =INT_MAX;
        int  n= matrix.size();
        for(int i =0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]<0){
                    cnt++;
                }
                if(matrix[i][j] ==0){
                    cnt2++;
                }
                mini = min(mini,abs(matrix[i][j]));
            }
        }
        long long sum =0;
         for(int i =0;i<n;i++){
            for(int j=0;j<n;j++){
                sum += abs(matrix[i][j]);
            }
        }
        if(cnt % 2 == 0) return sum;
        else if((cnt % 2 != 0)  &&  cnt2 !=0) return sum;

        return (long long)sum - (2*mini);
    }
};