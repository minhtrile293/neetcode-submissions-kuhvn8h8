
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        for(int n : nums){
            count[n]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        
        for(auto num : count){
            q.push({num.second, num.first});
            if(q.size() > k){
                q.pop();
            }
        }
        vector<int>result;
        for(int i = 0; i < k; i++){
            result.push_back(q.top().second);
            q.pop();
        } 
        return result;
    }
};
