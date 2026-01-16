class Solution {
public:
    long long M = 1e9+7;
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);

        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        unordered_set<int>widths;
        unordered_set<int>heights;

        for(int i =0 ;i<vFences.size();i++){
            for(int j =i+1 ;j<vFences.size();j++){
                int diff = vFences[j] - vFences[i];
                widths.insert(diff);
            }
        }

        int maxside = 0;
        for(int i =0 ;i<hFences.size();i++){
            for(int j =i+1 ;j<hFences.size();j++){
                int hei = hFences[j] - hFences[i];
                if(widths.find(hei) != widths.end()){
                    maxside = max(maxside, hei);
                }
            }
        }
        
        return maxside == 0? -1: ((long long)maxside*(long long)maxside) % M;

        
    }
};