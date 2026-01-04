class Solution {
    int factors(int n){
        int cnt=0;
        int sum=0;
        for(int i =2;i*i<=n;i++){
            if(n % i == 0){
                int j = n/i;
                if(cnt >0 || i==j ) return 0;
                sum = i+j;
                cnt++;
            }
        }
        return 1+sum+n;
    }
public:
    int sumFourDivisors(vector<int>& nums) {
        int sum=0;
        for(int i =0;i<nums.size();i++){
            sum += factors(nums[i]);
        }
        return sum;
    }
};