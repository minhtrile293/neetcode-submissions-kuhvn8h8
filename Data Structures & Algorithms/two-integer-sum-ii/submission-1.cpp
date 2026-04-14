class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;
        vector<int> result;
        while(l < r){
            int output = numbers[l] + numbers[r];
            if( output == target){
                result.push_back(l + 1);
                result.push_back(r + 1);
                return result;
            } else if (output > target){
                r--;
            } else {
                l++;
            }
        }
        return result;
    }
};
