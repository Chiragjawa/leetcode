class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        vector<int> ans;
        sort(potions.begin(), potions.end());

        for (int spell : spells) {
            long long required = (success + spell - 1) / spell; 
            auto it = lower_bound(potions.begin(), potions.end(), required);
            int count = potions.end() - it;
            ans.push_back(count);
        }

        return ans;
    }
};
