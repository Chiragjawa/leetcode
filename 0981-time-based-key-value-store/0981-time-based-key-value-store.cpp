class TimeMap {
    unordered_map<string, vector<pair<int, string>> > time_map;
public:

    TimeMap() {
        time_map = {};
    }
    
    void set(string key, string value, int timestamp) {
        time_map[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        int n = time_map[key].size();
        int low =0;
        int high = n-1;
        int index =-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(time_map[key][mid].first <= timestamp){
                index=mid;
            }
            if(time_map[key][mid].first< timestamp){
                low= mid+1;
            }
            else{
                high = mid-1;
            }
        }

        return index==-1 ? "" :time_map[key][index].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */