#include <unordered_map>
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>freMap;
        for(auto num : nums){
            freMap[num]++;
        }
        vector<pair<int, int>> fre;
        for(auto num :freMap){
            fre.push_back(num);
        }
        sort(fre.begin(), fre.end(), [](auto &a, auto &b){
            return a.second < b.second;
        });
        vector<int>result;
        for(int i = fre.size() - 1; i >= 0; i-- ){
            if(k == 0) break;
            result.push_back(fre[i].first);
            k--;
        }
        return result;
    }
};
