#include <map>
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> result;
        vector<int> numsCopy;
        numsCopy = nums;
        sort(numsCopy.begin(), numsCopy.end());
        for(int i = 0; i < numsCopy.size(); i++){
            if(i > 0 && (numsCopy[i] == numsCopy[i - 1])) continue;
            vector<int>sum;
            int j = i + 1;
                int l = j;
                int r = numsCopy.size() - 1;
                int target = -numsCopy[i]; 
                while(l < r){ 
                    while(l > j && (numsCopy[l] == numsCopy[l - 1]))
                        l++;
                    int total = numsCopy[l] + numsCopy[r];
                    if(total == target){
                        sum.push_back(numsCopy[l]); 
                        sum.push_back(numsCopy[r]); 
                        sum.push_back(numsCopy[i]);
                        result.push_back(sum);
                        sum.clear();
                        l++; 
                    } else if (total > target) {
                        r--;
                    } else {
                        l++;
                    }
                }
        }
        return result;
    }
};
