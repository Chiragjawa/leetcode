class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        const long long INF = LLONG_MAX / 2;
        vector<vector<long long>>dist(26, vector<long long>(26, INF));
        for(int i =0;i<26;i++) dist[i][i]=0;

        for(int i =0 ;i< original.size();i++){
            dist[original[i]-'a'][changed[i]-'a'] = min(dist[original[i]-'a'][changed[i]-'a'], (long long) cost[i]);
        }

        for(int k=0;k<26; k++){
            for(int i =0 ;i<26;i++){
                for(int j =0;j<26;j++){
                    if(dist[i][k] +dist[k][j] < dist[i][j]){
                        dist[i][j] = dist[i][k]+dist[k][j];
                    }
                }
            }
        }
        long long ans=0;
        for(int i =0; i<source.size();i++){
            if(source[i] == target[i]){
                continue;
            }
            if(dist[source[i]-'a'][target[i]-'a'] == INF) return -1;
            ans +=dist[source[i]-'a'][target[i]-'a'];
            
        }
        return ans;
    }
};