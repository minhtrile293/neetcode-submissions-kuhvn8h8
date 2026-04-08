class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>result;
        int n = nums.size();
        vector<int>prefix(n, 0);
        vector<int>subfix(n, 0);
        long preTotal = 1;
        long subTotal = 1;
        
        for(int i = 0; i < n; i++){
            preTotal *= nums[i];
            subTotal *= nums[n - 1 - i];
            // 1(1) 2(1, 2) 8(1, 2, 4) 48(1, 2, 4, 6)
            // 48(full)      48(2 4 6)        24(4 6)           6 (6)
            prefix[i] = preTotal;
            subfix[n - 1 - i] = subTotal;
        }

        result.push_back(subfix[1]);
        for(int i = 1; i < n - 1; i++){
            result.push_back(prefix[i - 1] * subfix[i + 1]);
        }
        result.push_back(prefix[n - 2]);
        return result;
    }
};
