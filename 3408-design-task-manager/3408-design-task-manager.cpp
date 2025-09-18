class TaskManager {
    unordered_map<int, pair<int,int>> mp;
    priority_queue<pair<int,int>> pq;

public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto &num : tasks) {
            int userId = num[0], taskId = num[1], priority = num[2];
            mp[taskId] = {userId, priority};
            pq.emplace(priority, taskId);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        mp[taskId] = {userId, priority};
        pq.emplace(priority, taskId);
    }
    
    void edit(int taskId, int newPriority) {
        if (mp.count(taskId)) {
            mp[taskId].second = newPriority; 
            pq.emplace(newPriority, taskId);
        }
    }
    
    void rmv(int taskId) {
        if (mp.count(taskId)) {
            mp[taskId] = {-1, -1};
        }
    }
    
    int execTop() {
        while (!pq.empty()) {
            auto [p, taskId] = pq.top();
            auto &info = mp[taskId];
            
            if (info.second == p) { 
                int userId = info.first;
                mp[taskId] = {-1, -1};
                pq.pop();
                return userId;
            }
            pq.pop(); 
        }
        return -1;
    }
};
