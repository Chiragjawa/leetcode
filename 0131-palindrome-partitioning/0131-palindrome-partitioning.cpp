class Solution {
    int n;
    bool isPallindrome(int l, int r, string s){
        while(l < r){
            if(s[l] != s[r]) return false;
            l++; r--;
        }
        return true;
    }
    void func(string s, vector<vector<string>>&ans, vector<string>&temp, int ind){
        if(ind == n){
            ans.push_back(temp);
            return;
        }

        for(int i = ind;i<n;i++){
            if(isPallindrome(ind,i,s)){
                temp.push_back(s.substr(ind,i-ind+1));
                func(s,ans, temp,i+1);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        n = s.length();
        vector<vector<string>>ans;
        vector<string>temp;
        func(s,ans, temp, 0);
        return ans;
    }
};