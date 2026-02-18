class Solution {
public:
    bool hasAlternatingBits(int n) {
        string num = "";
        while(n>0){
            num += to_string(n % 2);
            n = n/2;
        }
        for(int i =0; i< num.size()-1 ;i++){
            if(num[i] == num[i+1]){
                return false;
            }
        }
        return true;
    }
};