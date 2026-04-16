class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLength = 0;
        unordered_set<char> charSet(s.begin(), s.end());
        for(int c : charSet){
            int count = 0;
            int l = 0;
            for(int r = 0; r < s.size(); r++){
                if(s[r] == c){
                    count++;
                }
                while((r - l + 1) - count > k && l < r){
                    if(s[l] == c){
                        count--;
                    }
                    l++;
                }
                maxLength = max(maxLength, r - l + 1);
            }
        }
        return maxLength;
    }
};
