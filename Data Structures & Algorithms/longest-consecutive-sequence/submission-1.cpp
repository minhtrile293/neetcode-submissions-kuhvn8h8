class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        int longestCount = 1;
        set<int> numbers;
        for(int num : nums){
            numbers.insert(num);
        }
        
        int count = 1;
        for(int num : numbers){
            if(numbers.find(num + 1) == numbers.end())
            {
                count = 1;
                continue;
            }
            count++;
            if(count > longestCount)
                longestCount = count;
        }
        
        return longestCount;
    }
};
