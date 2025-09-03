class Solution {
public:
    int getBeauty(unordered_map<char,int>& mp) {
        int maxi = INT_MIN, mini = INT_MAX;
        for (auto &each : mp) {
            maxi = max(maxi, each.second);
            mini = min(mini, each.second);
        }
        return maxi - mini;
    }

    int beautySum(string s) {
        int beautysum = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            unordered_map<char,int> mp;
            for (int j = i; j < n; j++) {
                mp[s[j]]++;
                beautysum += getBeauty(mp);
            }
        }
        return beautysum;
    }
};
