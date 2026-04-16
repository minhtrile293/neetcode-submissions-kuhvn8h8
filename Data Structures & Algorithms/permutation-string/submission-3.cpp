class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char,int> charS1;
        map<char,int>charSubstr;
        
        for(char c : s1){
            charS1[c]++;
        }
        int l = 0;
        bool track = true; 
        for(int r = 0; r < s1.size(); r++){
            charSubstr[s2[r]]++;
            if(charSubstr[s2[r]] > charS1[s2[r]]){
                charSubstr[s2[l]]--;
                l++;
                track = false;
            }
        }
        if(track)
            return true;
        for(int r = s1.size(); r < s2.size(); r++){
            charSubstr[s2[r]]++;
            if(charSubstr[s2[r]] > charS1[s2[r]]){
                while(charSubstr[s2[r]] > charS1[s2[r]]){
                    charSubstr[s2[l]]--;
                    l++;
                }
            }
            if(r - l + 1 == s1.size())
            {
                cout << l << " " << r << endl;
                return true;
            }
        }
        return false;
    }
};
