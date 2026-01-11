class Solution {
private:
    int largestRectangleArea(vector<int> heights) {
        stack<int> st;
        int maxarea = 0;
        int n = heights.size();

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int element = st.top(); st.pop();
                int pse = st.empty() ? -1 : st.top();
                int nse = i;
                maxarea = max(maxarea, heights[element] * (nse - pse - 1));
            }
            st.push(i);
        }

        while (!st.empty()) {
            int element = st.top(); st.pop();
            int pse = st.empty() ? -1 : st.top();
            int nse = heights.size();
            maxarea = max(maxarea, heights[element] * (nse - pse - 1));
        }

        return maxarea;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int n = matrix.size();
        int m = matrix[0].size();
        int maxarea = 0;

        // Step 1: Build column-wise prefix sum
        vector<vector<int>> heights(n, vector<int>(m, 0));

        for (int j = 0; j < m; j++) {
            int sum = 0;
            for (int i = 0; i < n; i++) {
                if (matrix[i][j] == '0') {
                    sum = 0;
                } else {
                    sum += (matrix[i][j] - '0');
                }
                heights[i][j] = sum;
            }
        }

        // Step 2: Use each row of heights[] as histogram
        for (int i = 0; i < n; i++) {
            maxarea = max(maxarea, largestRectangleArea(heights[i]));
        }

        return maxarea;
    }
};
