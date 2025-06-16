class Solution {
    private:
    int findmax(vector<int>& piles){
        int n=piles.size();
        int maxi = 0;
        for(int i=0;i<n;i++){
            maxi = max(maxi,piles[i]);
        }
        return maxi;
    }
    long long totalhours(vector<int>& piles , int mid){
        long long totalhrs=0;
        for(int i=0;i<piles.size();i++){
            totalhrs += ceil((double)piles[i]/(double)mid);
        }
        return totalhrs;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low= 1; 
        int high = findmax(piles);
        int ans = INT_MAX;
        while(low<= high){
            int mid= low +(high -low)/2;
            long long totalhrs = totalhours(piles , mid);

            if(totalhrs<=h){
                ans = mid;
                high = mid -1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};