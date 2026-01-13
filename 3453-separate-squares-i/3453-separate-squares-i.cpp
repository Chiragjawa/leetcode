class Solution {
int isarea(vector<vector<int>>& squares, double mid) {
    int n = squares.size();
    long double area1 = 0;
    long double area2 = 0;

    for (int i = 0; i < n; i++) {
        long double side = squares[i][2];   

        if (squares[i][1] >= mid) {
            area1 += side * side;
        } else if (squares[i][1] + side <= mid) {
            area2 += side * side;
        } else {
            area1 += ((squares[i][1] + side) - mid) * side;
            area2 += (mid - squares[i][1]) * side;
        }
    }

    if (fabsl(area1 - area2) < 1e-6) return 0;
    else if (area1 > area2) return -1;
    else return 1;
}
public:
    double separateSquares(vector<vector<int>>& squares) {
        double low = INT_MAX;
        for (int i = 0; i < squares.size(); i++) {
            low = min(low, (double)squares[i][1]);
        }

        double high = INT_MIN;

        for (int i = 0; i < squares.size(); i++) {
            double len = (squares[i][1] + squares[i][2]);
            high = max(high, len);
        }

        double ans = 0;

        while (high - low > 1e-6) {
            double mid = (low + high) / 2;
            int res = isarea(squares, mid);

            if (res == -1) {
                low = mid;
            } else {
                high = mid;
            }
        }

        return (low + high) / 2;
    }
};
