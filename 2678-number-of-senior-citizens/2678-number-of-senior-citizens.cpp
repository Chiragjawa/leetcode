class Solution {
public:
    int countSeniors(vector<string>& details) {
        int n= details.size();
        int count=0;
        for(int i=0 ;i<n ; i++){
            int age=0;
            string str=details[i];
            age= (str[11]-'0')*10+str[12]-'0';
            if(age>60){
                count++;
            }
        }
        return count;
    }
};