class Solution {
public:
    int cal(string s){
        int ans=0;
        for(char ch :s){
            ans += (ch -'a')+1;
        }
        return ans;
    }
    bool scoreBalance(string s) {
        int i=0;
        int j =1;
        while(j<s.size()){
            int first =cal(s.substr(i,j)) ;
            int second = cal(s.substr(j, s.size()-1));
            if(first == second){
                return true;
            }
            j++;
        }
        return false;
    }
};