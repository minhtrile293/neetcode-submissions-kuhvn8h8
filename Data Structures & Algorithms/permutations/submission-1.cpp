class Solution {
public:
//     1 2 3
// 2 1 3   3 2 1
// 2 3 1.  3 1 2

// 1 3 2
    vector<vector<int>> res;
    void backtrack(vector<int> &nums, int j){
        if(j == nums.size()){
            res.push_back(nums);
            return;
        }

        for(int i = j; i < nums.size(); i++){
            swap(nums[j], nums[i]);
            backtrack(nums, j + 1);
            swap(nums[j], nums[i]);
        }
    } 

    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums, 0);
        return res;
    }
};

