class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength = 0;
        int l = 0;
        int r = 0;
        set<char>present;
        while(r < s.size()){
            if(present.count(s[r]) == 0){
                present.insert(s[r]);
                r++;
                int length = r - l;
                maxLength = max(maxLength, length);
            } else {
                int length = r - l;
                maxLength = max(maxLength, length);
                while(present.count(s[r]) != 0){
                    present.erase(s[l]);
                    l++;
                }
            }
        }
        return maxLength;
    }
};
