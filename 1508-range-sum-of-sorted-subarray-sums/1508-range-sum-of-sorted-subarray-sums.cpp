class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int>sumarr;
        int MOD = 1e9 + 7;
        int count=0;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i ;j<n;j++){
                sum =sum +nums[j];
                sumarr.push_back(sum);
                count++;
            }
        }
        long long answer=0;
        sort(sumarr.begin(),sumarr.end());
        for(int i = left-1 ;i<right ; i++){
            answer = (answer+sumarr[i])%MOD;
        }
        return (int)answer;
    }
};