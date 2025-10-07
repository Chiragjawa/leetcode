class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        map<int, int> full;  // lake -> last day it rained
        vector<int> dryDays; // indices of 0s
        vector<int> ans(rains.size(), 1);

        for (int i = 0; i < rains.size(); i++) {
            if (rains[i] == 0) {
                dryDays.push_back(i);
            } else {
                int lake = rains[i];
                if (full.count(lake)) {
                    // find a dry day to empty this lake
                    auto it = lower_bound(dryDays.begin(), dryDays.end(),
                                          full[lake] + 1);
                    if (it == dryDays.end())
                        return {}; // no dry day available
                    ans[*it] = lake;
                    dryDays.erase(it);
                }
                full[lake] = i;
                ans[i] = -1;
            }
        }
    return ans;
    }
};
