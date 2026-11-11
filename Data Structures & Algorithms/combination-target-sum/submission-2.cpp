class Solution {
public:
    vector<vector<int>>combination;

    void backtracking(vector<int>& nums, vector<int>&subset, int target, int j){
        for(int i = j; i < nums.size(); i++){
            if(target - nums[i] > 0){
                subset.push_back(nums[i]);
                backtracking(nums, subset, target - nums[i], i);
                subset.pop_back();
            } else if(target - nums[i] == 0){
                subset.push_back(nums[i]);
                combination.push_back(subset);
                subset.pop_back();
                return;
            } else {
                return;
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> subset;
        backtracking(nums, subset, target, 0);
        return combination;
    }
};
