class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        string str = s;
        queue<string>q;
        q.push(str);
        unordered_set<string>vis;
        vis.insert(str);
        string small = str;
        while(!q.empty()){
            string cur = q.front(); q.pop();
            if(cur<small ) small = cur;
            string added = cur;
            for(int i=1; i<added.size() ;i+=2){
                added[i] = ((added[i]-'0' +a) % 10 ) +'0';
            }
            if(!vis.count(added)){
                vis.insert(added);
                q.push(added);
            }
             string rotated = cur.substr(cur.size() - b) + cur.substr(0, cur.size() - b);
            if (!vis.count(rotated)) {
                vis.insert(rotated);
                q.push(rotated);
            }
        }
        return small;
    }
};