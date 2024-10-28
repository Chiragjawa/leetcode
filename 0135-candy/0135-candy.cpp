class Solution {
public:
    int candy(vector<int>& ratings) {
        int sum=1,i=1;
        int n=ratings.size();
        while(i<n){
            if(ratings[i] == ratings[i-1]){
                sum = sum+1;
                i++;
                continue;
            }
            int peak =1;
            while(i<n && ratings[i]>ratings[i-1]){
                peak += 1; sum += peak ; i++;
            }
            int down =1;
            while(i<n && ratings[i]<ratings[i-1]){
                sum += down ; down++; i++;
            }
            if(down > peak){
                sum += down - peak;
            }
        }
        return sum;
    }
};