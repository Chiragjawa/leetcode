class Solution {
public:
 bool valid(unordered_map<char, int>& mp){
        int maxi = INT_MIN;
        int mini = INT_MAX;

        for(auto &it: mp){
            maxi = max(maxi, it.second);
            mini = min(mini, it.second);
        }
        if(maxi == mini) return true;
        return false;
    }
    int longestBalanced(string s) {
        int n = s.size();
        unordered_map<char, int> mp;
        int ans=0;
        for(int i =0;i<n;i++){
            mp.clear();
            for(int j=i;j<n;j++){
                mp[s[j]]++;
                if(valid(mp)){
                    ans = max(ans, j-i+1);
                }
            }
        }
        return ans;
    }
   
};