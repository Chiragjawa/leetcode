class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int>ans;
        long long i=1;
        int num =n;
        while(num!=0){
            if(num%10 !=0){
            ans.push_back((num%10)*(i));}
            num= num/10;
            i=i*10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};