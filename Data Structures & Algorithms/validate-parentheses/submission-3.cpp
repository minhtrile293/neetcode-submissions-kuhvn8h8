class Solution {
public:
    bool isValid(string s) {
        int n = s.length();
        stack<int>st;

        for(int i = 0; i < n; i++){
            if(s[i] == ')' || s[i] == '}' || s[i] == ']')
            {
                if(st.empty())
                    return false;
                char c = st.top();
                if(s[i] == ')'){
                    if(c != '(')
                        return false;
                } else if(s[i] == '}'){
                    if(c != '{')
                        return false;
                } else {
                    if(c != '[')
                        return false;
                }
                st.pop();
                continue;
            }
            st.push(s[i]);
        }
        if(st.empty())
            return true;
        return false;
    }
};
