class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string>parts;
        int start=0;
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i] == '1'){
                count++;
            }
            if(s[i]=='0'){
                count--;
            }
            if(count==0){
                string temp = s.substr(start+1 , i-start-1);
                parts.push_back("1"+makeLargestSpecial(temp)+"0");
                start = i+1;
            }
        }
        sort(parts.begin(),parts.end(),greater<string>());
        string ans="";

        for(auto w:parts) ans+=w;

        return ans;
    }
};