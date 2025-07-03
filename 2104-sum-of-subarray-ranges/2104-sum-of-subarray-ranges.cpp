class Solution {
public:
int mod=(int)(1e9+7);
vector<int> findnse(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[i] < arr[st.top()]) {
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    return ans;
}
vector<int> findpsee(vector<int>& arr)
{
    int n=arr.size();
    vector<int>ans(n,-1);
    ans[0]=-1;
    stack<int>st;
    st.push(0);
    for(int i=1;i<n;i++)
    {
        while(!st.empty()&&arr[st.top()]>arr[i])
        {
            st.pop();
        }
        if(st.empty()==false)
        ans[i]=st.top();
        st.push(i);
    }
    return ans;
}
    long long sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>nse=findnse(arr);
        vector<int>psee=findpsee(arr);
        long long total=0;
        for(int i=0;i<arr.size();i++)
        {
            int left=(psee[i]==-1)?(i+1):(i-psee[i]);
            int right=(nse[i]==-1)?(n-i):(nse[i]-i);
            long long contri=(left*right);
            long long neww=(contri*arr[i]);
            total=(total+neww);
        }
        return total;
    }

vector<int> findnle(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[i] > arr[st.top()]) {
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }

    return ans;
}
vector<int> findplee(vector<int>& arr)
{
    int n=arr.size();
    vector<int>ans(n,-1);
    ans[0]=-1;
    stack<int>st;
    st.push(0);
    for(int i=1;i<n;i++)
    {
        while(!st.empty()&&arr[st.top()]<arr[i])
        {
            st.pop();
        }
        if(st.empty()==false)
        ans[i]=st.top();
        st.push(i);
    }
    return ans;
}
    long long sumSubarrayMaxs(vector<int>& arr) {
        int n=arr.size();
        vector<int>nse=findnle(arr);
        vector<int>psee=findplee(arr);
        long long total=0;
        for(int i=0;i<arr.size();i++)
        {
            int left=(psee[i]==-1)?(i+1):(i-psee[i]);
            int right=(nse[i]==-1)?(n-i):(nse[i]-i);
            long long contri=(left*right);
            long long neww=(contri*arr[i]);
            total=(total+neww);
        }
        return total;
    }
    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxs(nums)-sumSubarrayMins(nums);
    }
};