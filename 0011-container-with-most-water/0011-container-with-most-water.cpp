class Solution {
public:
    int maxArea(vector<int>& height) {
        int left =0;
        int right=height.size()-1;
        int curr=0;
        int maxwater=0;
        while(left<right){
            curr = min(height[left],height[right])*(right-left);
            maxwater= max(maxwater,curr);
            if(height[left]>height[right]){
                right--;
            }
            else{
                left++;
            }
        }
        return maxwater;
    }
};