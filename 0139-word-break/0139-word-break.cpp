class Solution {
private:
    bool func(int i, string &s, vector<string>& wordDict, vector<int>& dp, unordered_set<string>& dict){
        if(i >= s.size()) return true;
        if(dp[i] != -1) return dp[i];

        string str = "";
        for(int a = i; a < s.size(); a++){
            str += s[a];
            if(dict.count(str) && func(a+1, s, wordDict, dp, dict)){
                return dp[i] = true;
            }
        }
        return dp[i] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<int> dp(n, -1);
        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        return func(0, s, wordDict, dp, dict);
    }
};
