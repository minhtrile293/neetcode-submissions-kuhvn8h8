#include <unordered_map>
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> group;
        for(string s : strs){
            bool isAdded = false;

            for(int i = 0; i < group.size(); i++){
                string comp = group[i][0];
                string temp = s;
                sort(comp.begin(), comp.end());
                sort(temp.begin(), temp.end());
                if (comp == temp){
                    group[i].push_back(s);
                    isAdded= true;
                    break;
                }
            }
            if(isAdded == false){
                vector<string>sublist;
                sublist.push_back(s);
                group.push_back(sublist);
            }
        }
        return group;
    }
};
