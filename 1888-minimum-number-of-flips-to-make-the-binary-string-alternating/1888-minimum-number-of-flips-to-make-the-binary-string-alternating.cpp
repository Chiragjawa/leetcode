class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string ss =s+s;
        int diff1 =0;
        int ans=INT_MAX;
        int diff2 =0;
        for( int i =0; i<ss.size();i++){
            char exp1 = (i %2 ) ? '1' : '0';
            char exp2 = (i %2 ) ? '0' : '1';
            if(ss[i] != exp1) diff1++;
            if(ss[i] != exp2) diff2++;

            if(i>=n){
                char pewv = ss[i -n];

                char exxp1 =((i - n) % 2) ? '1' : '0';
                char exxp2 =((i - n) % 2) ? '0' : '1';

                if(pewv != exxp1) diff1--;
                if(pewv != exxp2) diff2--;
            }
            if(i >= n-1){
                int x =min(diff1 , diff2);
                ans = min(ans,x);
            }
        }
        return ans;
    }
};