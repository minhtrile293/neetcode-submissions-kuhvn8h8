class Solution {
public:

    string encode(vector<string>& strs) {
        string result = "";
        for(auto str : strs){
            result += str + "Tr";
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        while(s != ""){
            int index = s.find("Tr");
            string str = s.substr(0, index);
            s.erase(0, index + 2);
            result.push_back(str);
        }
        return result;
    }
};
