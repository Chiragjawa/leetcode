class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int i = 0;
        char ans = letters[0];

        while (i < letters.size()) {
            if (letters[i] > target) {
                ans = letters[i];
                break;
            }
            i++; 
        }
        return ans;
    }
};
