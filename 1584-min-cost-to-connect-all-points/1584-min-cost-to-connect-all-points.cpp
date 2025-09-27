class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> dist(n, INT_MAX);
        vector<bool> inMST(n, false);

        dist[0] = 0;
        int ans = 0;

        for (int k = 0; k < n; k++) {
            int u = -1;
            for (int i = 0; i < n; i++) {
                if (!inMST[i] && (u == -1 || dist[i] < dist[u])) {
                    u = i;
                }
            }

            ans += dist[u];
            inMST[u] = true;
            for (int v = 0; v < n; v++) {
                if (!inMST[v]) {
                    int cost = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                    dist[v] = min(dist[v], cost);
                }
            }
        }
        return ans;
    }
};
