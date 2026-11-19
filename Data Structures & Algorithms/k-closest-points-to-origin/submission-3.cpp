struct Compare{
    bool operator()(vector<int>&a, vector<int>&b){
        float gap_1 = sqrt(pow(a[0], 2) + pow(a[1], 2));
        float gap_2= sqrt(pow(b[0], 2) + pow(b[1], 2));
        return gap_1 > gap_2;
    }
};
class Solution {
public:

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, Compare> q;
        for(auto point : points){
            q.push(point);
        }
        vector<vector<int>> res;
        for(int i = 0; i < k; i++){
            vector<int> point = q.top();
            q.pop();
            res.push_back(point);
        }
        return res;
    }
};
