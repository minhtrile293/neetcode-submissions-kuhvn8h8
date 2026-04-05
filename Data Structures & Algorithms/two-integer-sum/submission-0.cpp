#include <unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indices;
        unordered_map<int, int>position;
        for(int i = 0; i < nums.size(); i++){
            int part = target - nums[i];
            if(position.find(part) != position.end())
                return {position[part], i};
            position[nums[i]] = i;
        }
    }
};
