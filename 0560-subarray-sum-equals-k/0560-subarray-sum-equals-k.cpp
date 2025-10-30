class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp.insert({0,1});
        int prefix=0;
        int count =0;
        for(int i=0;i<nums.size();i++){
            prefix += nums[i];
            int ind = prefix-k;
            if(mp.find(ind) != mp.end()){
                count += mp[ind];
                mp[prefix]++;
            }
            else{
                mp[prefix]++;
            }
        }
        return count;
    }
};