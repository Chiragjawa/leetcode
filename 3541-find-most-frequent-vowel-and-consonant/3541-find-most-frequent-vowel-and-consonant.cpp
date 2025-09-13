class Solution {
public:
    int maxFreqSum(string s) {
        unordered_map<char,int>freq;
        for(int ch:s) freq[ch]++;
        int maxv=0;
        int maxc=0;
        string vowel ="aeiou";
        for(int ch:s){
            if(vowel.find(ch)!= string::npos){
                maxv = max(maxv , freq[ch]);
            }
            else{
                maxc = max(maxc, freq[ch]);
            }
        }
        return maxc+maxv;
    }
};