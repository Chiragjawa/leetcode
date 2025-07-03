class Solution {
private:
    vector<int> findnse(vector<int>&arr){
        vector<int>nse(arr.size());
        stack<int>st;
        for(int i= arr.size()-1 ;i>=0 ;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            nse[i] = st.empty() ? arr.size() : st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int> findpse(vector<int>&arr){
        vector<int>pse(arr.size());
        stack<int>st;
        for(int i=0 ;i<arr.size() ;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int>nse = findnse(arr);
        vector<int>pse = findpse(arr);
        long long total=0;
       int mod = 1e9 + 7;
        for(int i=0 ;i<arr.size();i++){
            int left = i - pse[i];
            int right = nse[i] -i;
            total = (total + ( (long long)right * left * arr[i])%mod)%mod;
        }
        return total;
    }
};