class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.size() == 1)
            return stoi(tokens[0]);
    
        stack<int> st;
        for(int i = 0; i < tokens.size(); i++){
            if((tokens[i][0] >= '0' && tokens[i][0] <= '9') || tokens[i].size() >= 2){
                st.push(stoi(tokens[i]));
                continue;
            }
            int a, b;
            a = st.top();
            st.pop();
            b = st.top();
            st.pop();
            if(tokens[i][0] == '+'){
                st.push(b + a);
            } else if(tokens[i][0] == '-'){
                st.push(b - a);
            } else if(tokens[i][0] == '*'){
                st.push(b * a);
            } else {
                cout << b << a << endl;
                st.push(b / a);
            }
            cout << st.top() << endl;
        }
        return st.top();
    }
};
