class Solution {
private:
int sumofd(vector<int>&nums , int mid){
    int sum=0;
    for(int i=0;i<nums.size();i++){
        sum+= ceil((double)(nums[i]) / (double)(mid));
    }
    return sum;
}
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        if(nums.size()>threshold) return -1;
        int ans=0;
        int low=1; int high = *max_element(nums.begin(), nums.end()); ;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(sumofd(nums,mid)<= threshold){
                ans = mid;
                high = mid-1;
            }
            else{
                low= mid+1;
            }
        }
        return ans;
    }

};