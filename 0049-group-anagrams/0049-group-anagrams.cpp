class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
     unordered_map<string, vector<string>> stringMap;
        int i;
        vector<vector<string>> res;
        
        for (i = 0; i < strs.size(); i++) {
            string sortedString = strs[i];
            sort(sortedString.begin(), sortedString.end());
            stringMap[sortedString].push_back(strs[i]);
        }
        
        for (auto it = stringMap.begin(); it != stringMap.end(); it++) {
            res.push_back(it->second);
        }
        
        return res;
    }
};