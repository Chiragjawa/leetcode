class Solution {
public:
    int minPartitions(string n) {
       string num = string(n);
       int ans = INT_MIN;
       for(int i =0 ;i< num.size();i++) {
        int x = num[i] -'0';
        ans = max(ans,x);
       }
       return ans;
    }
};