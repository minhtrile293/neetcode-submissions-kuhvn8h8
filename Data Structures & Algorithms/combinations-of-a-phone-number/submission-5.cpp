class Solution {
public:
    vector<string>res;
    map<int, string> mapped;
    void backtrack(string& sub, string& digits, int k){
        if(k >= digits.length()){
            res.push_back(sub);
            return;
        }
        int digit = digits[k] - '0';
        int n = mapped[digit].length();
        for(int i = 0; i < n; i++){
            sub += mapped[digit][i];
            backtrack(sub, digits, k + 1);
            sub.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        res.clear();
        if(digits.length() == 0)
            return res;
        char alpha = 'a'; 
        for(int i = 2; i <= 6; i++){
            mapped[i] += alpha;
            for(int j = 1; j <= 2; j++){
                alpha++;
                mapped[i] += alpha; 
            }
            alpha++;
        }
        mapped[7] = "pqrs";
        mapped[8] = "tuv";
        mapped[9] = "wxyz";
        string sub = "";
        backtrack(sub, digits, 0);
        return res;
    }
};
