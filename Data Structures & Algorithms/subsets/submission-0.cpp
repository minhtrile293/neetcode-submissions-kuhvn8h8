class Solution {

private:
    vector<vector<int>> sets;
    void backtracking(vector<int>& subSet, vector<int>& nums, int j) {
        sets.push_back(subSet);
        for(int i = j + 1; i < nums.size(); i++){
            subSet.push_back(nums[i]);
            backtracking(subSet, nums, i);
            subSet.pop_back(); 
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>subSet;
        backtracking(subSet, nums, -1);
        return sets;
    }
};
