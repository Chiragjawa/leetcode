class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (k > s.size()) return false;
        unordered_set<string>mp;

       for(int i =0;i+k<=s.size();i++) {
            string ans = s.substr(i, k);
            mp.insert(ans);
        }
        return mp.size() == (1<<k);
    }
};