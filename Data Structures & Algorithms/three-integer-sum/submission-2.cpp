#include <map>
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> result;
        vector<int> numsCopy;
        numsCopy = nums;
        sort(numsCopy.begin(), numsCopy.end());
        map<int, set<pair<int, int>>> tracker;
        for(int i = 0; i < numsCopy.size(); i++){
            vector<int>sum;
            for(int j = i + 1; j < numsCopy.size(); j++){
                int l = j;
                int r = numsCopy.size() - 1;
                int target = -numsCopy[i];
                while(l < r){
                    int total = numsCopy[l] + numsCopy[r];
                    if(total == target){
                        sum.push_back(numsCopy[l]);
                        sum.push_back(numsCopy[r]);
                        sum.push_back(numsCopy[i]);
                        tracker[numsCopy[i]].insert({numsCopy[l], numsCopy[r]});
                        sum.clear();
                        l++;
                    } else if (total > target) {
                        r--;
                    } else {
                        l++;
                    }
                }
            }
        }
        vector<int> sum;
        for (auto [key,value] : tracker){
            for (auto v : value){
                sum.push_back(key);
                sum.push_back(v.first);
                sum.push_back(v.second);
                result.push_back(sum);
                sum.clear();
            }
        }
        return result;
    }
};
