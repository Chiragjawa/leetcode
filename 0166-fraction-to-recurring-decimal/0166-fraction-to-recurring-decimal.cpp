class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator==0){
            return "0";
        }
        string res = "";
        if( numerator<0 ^ denominator<0 ) res.push_back('-');

        long long n = llabs((long long )numerator);
        long long m = llabs((long long )denominator);
        res += to_string(n / m);
        long long rem = n%m;
        if(rem == 0) 
            return res;

        res.push_back('.');
        unordered_map<long long, int> seen;

        while (rem != 0) {
            if (seen.find(rem) != seen.end()) {
                int pos = seen[rem];
                res.insert(pos, "(");
                res.push_back(')');
                break;
            }
            seen[rem] = res.size();
            rem *= 10;
            int digit = rem / m;
            res.push_back(char('0' + digit));
            rem = rem %m;
        }
        return res;

    }
};