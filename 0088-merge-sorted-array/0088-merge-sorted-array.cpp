class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int b=0;
        for(int i=0;i<n;i++){
            nums1[m]=nums2[b];
            m++;
            b++;
        }
        sort(nums1.begin(),nums1.end());
    }
};