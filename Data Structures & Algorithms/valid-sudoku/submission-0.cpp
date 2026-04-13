class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_map<char, int>>rowTracker(9);
        vector<unordered_map<char, int>>colTracker(9);
        vector<unordered_map<char,int>>boxTracker(9);
        
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board.size(); j++){
                if(board[i][j] == '.'){
                    continue;
                }
                if(rowTracker[i][board[i][j]] > 0 || colTracker[j][board[i][j]] > 0){
                    return false;
                } 
                rowTracker[i][board[i][j]]++;
                colTracker[j][board[i][j]]++;
                int boxIndex = (i / 3) * 3 + (j / 3);
                if(boxTracker[boxIndex][board[i][j]] > 0)
                    return false;
                boxTracker[boxIndex][board[i][j]]++;
            }
        }
        return true;
    }
};
