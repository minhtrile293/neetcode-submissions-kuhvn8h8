class Solution {
public:
    vector<vector<int>> combination;
    void backtrack(vector<int>& candidates, int target, vector<int>& subset, int j){
        if(target == 0){
            combination.push_back(subset);
            return;
        }
        int preCandidate = 0;
        for(int i = j + 1; i < candidates.size(); i++){
            if(candidates[i] > target)
                return;  
            if(candidates[i] == preCandidate)
                continue;
            preCandidate = candidates[i];
            subset.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], subset, i);
            subset.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>subset;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, subset, -1);
        return combination;
    }
};
