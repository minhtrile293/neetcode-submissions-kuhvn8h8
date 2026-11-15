class Solution {
public:
    vector<string>res; 
    void backtrack(string pa, int n, int step){
        if(n == 0){
            res.push_back(pa);
            return;
        }
        int len = pa.length();
        while(step <= len){
            pa.insert(step, "()");
            n--;
            backtrack(pa, n, step + 1);
            n++;
            pa.erase(step, 2);
            step++;
        }
    }
    vector<string> generateParenthesis(int n) {
        string pa = "";
        backtrack(pa, n, 0); 
        return res;
    }
    

// "()"
// => "(())"
//     =>"((()))"
//     =>"(()())"
//     =>"(())()"
// => "()()"
//     =>"()(())"
//     =>"()()()"

};
