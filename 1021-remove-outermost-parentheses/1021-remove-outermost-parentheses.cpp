class Solution {
public:
    string removeOuterParentheses(string s) {
        int count=0;
        string res ="";
        for(int i=0 ;i<s.size();i++){
            if(s[i] == '('){
               if(count>0){
                res+=s[i];
               }
               count++;
            }
            else{
                count--;
                if(count>0){
                    res+=s[i];
                }
            }

        }
        return res;
    }
};