class Solution {
public:
    int triangularSum(vector<int>& nums) {
        queue<int> q;
        for (int x : nums) q.push(x);

        while (q.size() > 1) {
            int n = q.size();
            int prev = q.front();
            q.pop();

            for (int i = 1; i < n; i++) {
                int curr = q.front();
                q.pop();
                q.push((prev + curr) % 10);
                prev = curr;
            }
        }
        return q.front();
    }
};
