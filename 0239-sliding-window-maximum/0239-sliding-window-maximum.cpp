class Solution {
private:
    void newpq(priority_queue<pair<int,int>>&pq, int l,int r, vector<int>& nums){
        for(int i=l;i<=r;i++){
            pq.push({nums[i],i});
        }
    }
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        int l=0;
        int r=l+k-1;
        priority_queue<pair<int,int>>pq;
        for(int i=l;i<=r;i++){
            pq.push({nums[i],i});
        }
        while(r<nums.size()){
            if(pq.top().second<l){
                pq.pop();
                newpq(pq,l,r,nums);
            }else{
                pq.push({nums[r],r});
            }
            auto [x,y] = pq.top();
            
            ans.push_back(x);  
            l++;
            r++;
        }
        return ans;
    }
};