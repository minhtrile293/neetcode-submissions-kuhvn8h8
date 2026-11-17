class Solution {
public:
    void backtrack(int open, int close, int n, vector<string>& res, string& state){
        if(open == close && open == n){
            res.push_back(state);
            return;
        }
        if(open < n){
            state += '(';
            backtrack(open + 1, close, n, res, state);
            state.pop_back();
        }
        if(close < open){
            state += ')';
            backtrack(open, close + 1, n, res, state);
            state.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string>res;
        string state;
        backtrack(0, 0, n, res, state);
        return res;
    }
};
