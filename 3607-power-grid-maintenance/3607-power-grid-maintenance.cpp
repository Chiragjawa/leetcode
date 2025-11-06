class Solution {
public:
    vector<int> parent, rnk;

    int findp(int x) {
        return parent[x] == x ? x : parent[x] = findp(parent[x]);
    }

    void unite(int a, int b) {
        a = findp(a);
        b = findp(b);
        if (a != b) {
            if (rnk[a] < rnk[b]) swap(a, b);
            parent[b] = a;
            if (rnk[a] == rnk[b]) rnk[a]++;
        }
    }

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<vector<int>> adj(c + 1);
        vector<int> ans;

        parent.resize(c + 1);
        rnk.assign(c + 1, 0);
        for (int i = 1; i <= c; i++) parent[i] = i;

        for (auto& it : connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            unite(it[0], it[1]);
        }

        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> compPQ;
        set<int> st;
        vector<int> online(c + 1, 1);

        for (int i = 1; i <= c; i++) {
            st.insert(i);
            int root = findp(i);
            compPQ[root].push(i);
        }

        for (auto& it : queries) {
            int type = it[0], x = it[1];
            int root = findp(x);

            if (type == 1) {
                if (online[x]) {
                    ans.push_back(x);
                } else {
                    while (!compPQ[root].empty() && !online[compPQ[root].top()]) {
                        compPQ[root].pop();
                    }
                    if (compPQ[root].empty()) ans.push_back(-1);
                    else ans.push_back(compPQ[root].top());
                }
            } else {
                online[x] = 0;
                st.erase(x);
            }
        }

        return ans;
    }
};
