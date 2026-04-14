#include <ctype.h>

class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.length() - 1;
        while(l < r){
            while(l < r && !isAlpha(s[l])){
                l++;
            }
            while(l < r && !isAlpha(s[r])){
                r--;
            }

            if(tolower(s[l]) != tolower(s[r]))
                return false;
            l++;
            r--;
        }
        return true;
    }
    bool isAlpha(char c){
        return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'));
    }
};