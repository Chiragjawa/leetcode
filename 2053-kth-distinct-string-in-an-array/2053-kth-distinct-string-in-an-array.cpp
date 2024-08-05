class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int>m;
        string answer= "";
        int count=0;
        int size = arr.size();
        for(int i=0 ;i<size ;i++){
            m[arr[i]]++;
        }
        for(int i=0 ;i<size ;i++){
            if(m[arr[i]]==1){
                count++;
            }
            if(count==k){
                answer = arr[i];
                return answer;
            }
        }
        return answer;

    }
};