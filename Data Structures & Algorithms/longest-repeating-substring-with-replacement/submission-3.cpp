class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLength = 0;
        int l = 0;
        unordered_map<char, int> fre;
        int maxFre = 0;
        for(int r = 0; r < s.size(); r++){
            fre[s[r]]++;
            maxFre = max(maxFre, fre[s[r]]);
            while((r - l + 1) - maxFre > k){
                fre[s[l]]--;
                l++;
            }
            maxLength = max(maxLength, r - l + 1);
        }
        return maxLength;
    }
};
