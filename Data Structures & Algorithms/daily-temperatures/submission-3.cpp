class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>result(n, 0);
        stack<pair<int, int>> st; // temp, index
        for(int i = 0; i < n; i++){
            while(!st.empty() && st.top().first < temperatures[i]){
                auto t = st.top();
                st.pop();
                result[t.second] = i - t.second;
            }
            st.push({temperatures[i], i});
        }
        return result;
    }
};
