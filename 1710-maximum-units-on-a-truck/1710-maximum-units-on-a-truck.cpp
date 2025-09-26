class Solution {
private:
    static bool compare(const vector<int>&v1 , vector<int>&v2){
        return v1[1] >v2[1];
    }
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin() ,boxTypes.end(),compare);
        int ans=0;
        int cap = truckSize;
        for(auto box:boxTypes){
            int x = min(box[0] , cap);
            ans += (x*box[1]);
            cap-=x;
            if(cap == 0){
                break;
            }
        }
        return ans;
    }
};