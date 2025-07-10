class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0;
        for (char ch : s) {
            if (ch == '(') {
                low++;
                high++;
            } else if (ch == ')') {
                low--;
                high--;
            } else { // ch == '*'
                low--;   // treat * as ')'
                high++;  // treat * as '('
            }

            if (low < 0) low = 0;
            if (high < 0) return false;
        }

        return low == 0;
    }
};