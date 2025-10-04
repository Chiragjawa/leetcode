class Solution {
    bool matches(unordered_map<int,int>mp1, unordered_map<int,int>mp2){
        for(int i=0;i<26;i++){
            if(mp1[i] != mp2[i]) return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<int,int>mp1;
        unordered_map<int,int>mp2;
        for(char ch :s1){
            mp1[ch-'a']++;
        }
        int left=0;
        int right=0;
        while(right < s2.size()){
            mp2[s2[right]-'a']++;

            if((right-left+1)>s1.size()){
                mp2[s2[left]-'a']--;
                left++;
            }
            if(s1.size() == right-left+1 && matches(mp1,mp2)){
                return true;
            }
            right++;
        }
        return false;
    }
};