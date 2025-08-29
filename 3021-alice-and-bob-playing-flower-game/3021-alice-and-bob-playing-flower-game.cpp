class Solution {
public:
    long long flowerGame(int n, int m) {
        long long n_ceil = (n + 1) / 2; // ceil(n/2)
        long long n_floor = n / 2;      // floor(n/2)
        long long m_ceil = (m + 1) / 2; // ceil(m/2)
        long long m_floor = m / 2;      // floor(m/2)

        return n_ceil * m_floor + n_floor * m_ceil;
    }
};
