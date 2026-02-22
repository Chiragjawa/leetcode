class Solution {
    string toBinary(int n) {
    if (n == 0) return "0";

    string s = "";

    while (n > 0) {
        s = char('0' + (n % 2)) + s;
        n /= 2;
    }

    return s;
}
public:
    int binaryGap(int n) {
        string num = toBinary(n);
        int z =-1; 
        int ans =0;
        for(int i =0;i<num.size();i++){
            if(num[i] == '1'){
                if(z != -1){
                    ans = max(ans, i-z);
                }
                z =i;
            }
        }
        return ans;
    }
};