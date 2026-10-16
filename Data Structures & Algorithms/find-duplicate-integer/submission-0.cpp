class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        set<int>se;
        for(int i = 0; i < nums.size(); i++){
            if(se.count(nums[i])){
                return nums[i]; 
            } 
            se.insert(nums[i]);
        }
        return 1;
    }
};
