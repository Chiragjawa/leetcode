class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        unordered_map<int,int>map;
        int i=0;
        int j=0;
        int ans=0;
        while(j<arrivals.size()){
            map[arrivals[j]]++;
            while(j-i+1>w){
                map[arrivals[i]]--;
                i++;
            }
            if(map[arrivals[j]]>m){
                ans++;
                map[arrivals[j]]--;
                arrivals[j] = 0; 
            }
            j++;
        }
        return ans;
    }
};