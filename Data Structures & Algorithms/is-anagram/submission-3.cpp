#include <map>
#include <unordered_map>

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> s_map;
        unordered_map<char, int> t_map;
        for(char i : s){
            if(s_map.count(i) == 0)
                s_map[i] = 1;
            else
                s_map[i]++;
        }

        for(char i : t){
            if(t_map.count(i) == 0)
                t_map[i] = 1;
            else
                t_map[i]++;
        }

        if(s_map.size() != t_map.size()){
            return false;
        }

        for(pair<char, int>it : s_map){
            if(t_map.find(it.first) == t_map.end() || t_map[it.first] != it.second)
                return false;
        }
        return true;
    }
};
