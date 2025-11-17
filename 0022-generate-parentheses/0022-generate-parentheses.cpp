class Solution {
private:
    void func(string str, vector<string>& res, int open, int close) {
        if (open == 0 && close == 0) {
            res.push_back(str);
            return;
        }
        if (open > 0) {
            func(str + "(", res, open - 1, close);
        }
        if (close > open) {
            func(str + ")", res, open, close - 1);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        func("", res, n, n);
        return res;
    }
};
