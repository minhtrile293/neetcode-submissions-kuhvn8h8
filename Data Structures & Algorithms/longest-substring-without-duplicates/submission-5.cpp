class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        int l = 0;
        unordered_map<char, int>position;
        for(int r = 0; r < s.size(); r++){
            if(position.count(s[r]) != 0){
                l = max(l, position[s[r]] + 1);
            }
            position[s[r]] = r;
            maxLength = max(maxLength, r - l + 1);
        }
        return maxLength;
    }
};
