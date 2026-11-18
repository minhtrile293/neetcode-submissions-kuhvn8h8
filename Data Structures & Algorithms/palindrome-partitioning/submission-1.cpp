class Solution {
public:
    vector<vector<string>> res;
    bool isPalindrome(string t){
        string tmp = "";
        for(char c : t){
            tmp = c + tmp; 
        }
        return tmp == t;
    }

    void backtrack(vector<string>& parts, string& s, string& sub, int i){
        if(i >= s.length()){
            if(sub == "")
                res.push_back(parts);
            return;
        }
        
        sub += s[i];
        if(isPalindrome(sub)){
            string tmp = sub;
            parts.push_back(sub);
            sub = "";
            backtrack(parts, s, sub, i + 1);
            sub = tmp;
            parts.pop_back();
        }
        backtrack(parts, s, sub, i + 1);
        
    }

    vector<vector<string>> partition(string s) {
        vector<string> parts;
        string sub = "";
        backtrack(parts, s, sub, 0);
        return res;
    }
};
