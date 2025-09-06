class Solution {
public:
    void fillSieve(vector<bool>& sieve){
        int n = sieve.size()-1;
        for(int i=2;i<=sqrt(n);i++){
            for(int j=i*2;j<=n;j+=i) sieve[j]=0;
        }
        return;
    }
    int countPrimes(int n) {
        if(n==0 || n==1 || n==2) return 0;
        // sieve eratosthenes method
        vector<bool> sieve(n,1); // 1 -> Prime, 0 -> Composite/Not Prime
        sieve[0] = 0, sieve[1] = 0;
        fillSieve(sieve);
        int count = 0;
        for(int i=2;i<n;i++){
            if(sieve[i]==1) count++;
        }
        return count;
    }
};