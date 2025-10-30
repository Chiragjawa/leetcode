class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int left=0;
      int right =0;
      vector<int>mp(256,-1);
      int ans=0;
      while(right<s.size()){
        if(mp[s[right] ] !=-1){
            left = max(left, mp[s[right]]+1);
        }        
        mp[s[right]]= right;
        ans = max(ans , right-left+1);
        right++;
      }
      return ans;
    }
};