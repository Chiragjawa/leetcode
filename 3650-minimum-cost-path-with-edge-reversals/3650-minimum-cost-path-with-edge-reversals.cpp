class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][1]].push_back({edges[i][0], 2 * edges[i][2]});
        }
        return dij(adj, 0);
    }
    int dij(vector<vector<pair<int, int>>> adj, int src) {
        int v = adj.size();
        vector<int> dist(v, INT_MAX);
        dist[src] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        pq.emplace(0, src);

        while (!pq.empty()) {
            auto topp = pq.top();
            pq.pop();

            int d = topp.first;
            int u = topp.second;

            if (d > dist[u]) {
                continue;
            }

            for (auto& it : adj[u]) {
                int v = it.first;
                int w = it.second;

                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v);
                }
            }
        }

        if (dist[v - 1] == INT_MAX)
            return -1;

        return dist[v - 1];
    }
};