class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxAmount = 0;
        int l = 0;
        int r = heights.size() - 1;
        while(l < r){
            int amount = min(heights[l], heights[r]) * (r - l);
            if(amount > maxAmount){
                maxAmount = amount;
            }
            if(heights[l] < heights[r]){
                l++;
            } else {
                r--;
            }
        }
        return maxAmount;
    }
};
