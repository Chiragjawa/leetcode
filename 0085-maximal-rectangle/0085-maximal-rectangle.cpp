class Solution {
    int maxarea(vector<int>height){
        int n = height.size();
        int maxarea=0;
        for(int i =0 ;i<n;i++){
            stack<int>st;
            int maxi=0;

            for(int i =0;i<=n;i++){
                int h = (i==n)? 0 : height[i];
                while(!st.empty() && h<height[st.top()]){
                    int hei = height[st.top()];
                    st.pop();
                    int width = st.empty() ? i : i-st.top() -1;
                    maxi = max(maxi,hei*width);
                }
                st.push(i);
            }
            maxarea = max(maxarea , maxi);
        }
        return maxarea;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int>height(m);
        for(int i =0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == '1') height[j]++;
                cout<<height[j];
            }
            cout<<endl;
        }

        return maxarea(height);
    }
};