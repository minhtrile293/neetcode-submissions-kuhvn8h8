class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, float>> cars;
        int n = position.size();
        
        for(int i = 0; i < n; i++){
            float time = (float)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }
        sort(cars.rbegin(), cars.rend());
        stack<float>st;
        st.push(cars[0].second);
        cout << cars[0].second << endl;
        for(int i = 1; i < n; i++){
            //cout << cars[i].second << endl;
            if(cars[i].second > st.top()){     
                st.push(cars[i].second);
            }
        }
        
        return st.size();
    }
};
