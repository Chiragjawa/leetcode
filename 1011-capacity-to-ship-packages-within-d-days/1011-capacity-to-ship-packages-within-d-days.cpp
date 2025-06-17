class Solution {
private:
    int finddays(vector<int>&weights , int mid){
        int days=1; int load =0;
        for(int i=0;i<weights.size();i++){
            if(weights[i]+load >mid){
                days+=1;
                load = weights[i];
            }
            else{
                load+=weights[i];
            }
        }
        return days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);
        int ans=high;
        while(low<=high){
            int mid = low +(high-low)/2;
            if( finddays(weights,mid) <= days){
                ans= mid;
                high =  mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};