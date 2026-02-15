class Solution {
public:
    string addBinary(string a, string b) {
        char carr = '0';
        string sol = "";
        int n = a.size() - 1;
        int m = b.size() - 1;

        while (n >= 0 || m >= 0) {
            char x = (n >= 0) ? a[n] : '0';
            char y = (m >= 0) ? b[m] : '0';

            int sum = (x - '0') + (y - '0') + (carr - '0');

            if (sum % 2 == 0)
                sol += '0';
            else
                sol += '1';

            if (sum >= 2)
                carr = '1';
            else
                carr = '0';

            n--;
            m--;
        }

        if (carr == '1')
            sol += '1';

        reverse(sol.begin(), sol.end());
        return sol;
    }
};
