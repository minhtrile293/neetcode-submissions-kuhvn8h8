class Solution {
public:
    bool res = false;
    unordered_map<int, int>visited;
    void backtrack(vector<vector<char>>& board, string& word, int i, int j, int k){
        if(i >= board.size() || j >= board[0].size() || board[i][j] != word[k] || res){
            return;
        }
        if(visited[i * 10 + j] == 1){
            return;
        }
        if(k == word.length() - 1 && board[i][j] == word[k]){
            res = true;
            return;
        }
        visited[i * 10 + j] = 1; 

        backtrack(board, word, i + 1, j, k + 1);
        backtrack(board, word, i, j + 1, k + 1);
        backtrack(board, word, i - 1, j, k + 1);
        backtrack(board, word, i, j - 1, k + 1);
        
        visited[i * 10 + j] = 0;
    }

    bool exist(vector<vector<char>>& board, string word) {
        if(word == "")
            return false;
        string search = "";
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == word[0]){
                    backtrack(board, word, i, j, 0);
                    if(res)
                        return res;
                }
            }
        }
        return res;
    }

};
