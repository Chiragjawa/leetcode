class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
        int m = mat[0].size();
        int maxside = 0;
        if (n == 1 && m == 1) {
            if (mat[0][0] <= threshold)
                return 1;
            else {
                return 0;
            }
        }
        vector<vector<int>> pref(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (j == 0)
                    pref[i][j] = mat[i][j];
                else{
                    pref[i][j] = pref[i][j - 1] + mat[i][j];
                }
            }
        }
        for (int k = 0; k < min(n, m); k++) {
            bool possible = false;
            for (int i = 0; i + k < n; i++) {
                for (int j = 0; j + k < m; j++) {
                    if (solve(i, j, k, mat, pref, threshold) <= threshold) {
                        maxside = max(maxside, k + 1);
                        possible = true;
                        break;
                    }
                }
                if(possible) break;
            }
            // if(!possible) break;
        }
        return maxside;
    }
    int solve(int i, int j, int k, vector<vector<int>>& mat,
              vector<vector<int>>& pref, int threshold) {
        int sum = 0;
        for (int a = i; a <= i + k; a++) {
            if(j ==0){
                sum += pref[a][j+k];
            }
            else{
            sum = sum + (pref[a][j + k] - pref[a][j-1]);
            }
            if(sum> threshold) return sum;
        }
        cout << sum << endl;
        return sum;
    }
};