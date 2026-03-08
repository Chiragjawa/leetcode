class Solution {
public:
    unordered_set<string>st;
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        for(int i =0 ;i < n ;i++){
            st.insert(nums[i]);
        }
        return solve(0,nums[0].size(),"");
    }
     string solve(int idx, int n, string curr){
        if(idx == n){
            if(st.find(curr) == st.end()) return curr;
            return "";
        }

        string res = solve(idx + 1, n, curr + '0');
        if(res != "") return res;

        res = solve(idx + 1, n, curr + '1');
        if(res != "") return res;

        return "";
    }
};