class Solution {
public:
    int minOperations(string s) {
        unordered_set<char>mp;
        for(char ch: s){
            mp.insert(ch);
        }
        int cnt=0;
        for(auto el : mp){
            if(el == 'a'){
                continue;
            }
            int value = el-'a';
            cnt = max(cnt, 26-value); 
        }
        return cnt;
    }
};