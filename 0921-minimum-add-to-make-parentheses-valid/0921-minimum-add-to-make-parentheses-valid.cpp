class Solution {
public:
    int minAddToMakeValid(string s) {
        int count = 0, left = 0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            left++;
            else
            {
                // if(left==0)
                // count++;
                // else
                left--;
            }
        }
        return abs(left);
    
    }
};