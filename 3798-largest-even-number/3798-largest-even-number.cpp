class Solution {
public:
    string largestEven(string s) {
        int n = s.size();
        if(s[n-1] == '2') return s;
        int i =n-2;
        string ans = "";
        while(i>=0){
            if(s[i] == '2'){
                ans += s.substr(0,i+1);
                break;
            }
            i--;
        }
        return ans;
    }
};