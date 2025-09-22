class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>freq;
        int maxi=INT_MIN;
        for(int num : nums){
            freq[num]++;
            maxi = max(maxi,freq[num]);
        }
        int ans=0;
        for(auto it:freq){
            if(it.second == maxi){
                ans+=maxi;
            }
        }
        return ans;
    }
};