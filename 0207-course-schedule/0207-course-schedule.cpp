class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V= numCourses;
        int vector<int> adj[V];
        for(auto it : prerequisites){
            adj[it[i]].push_back(it[0]);
        }

        int indegree[V] ={0};
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }

        queue<int> q;
        for(int i=0;i<V;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        int count=0;
        while(!q.empty()){
            int node =q.front();
            q.pop();
            count++;
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        if(count == V) return true;
        return false;
    }
};