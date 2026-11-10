class TrieNode {
    public:
        unordered_map<char, TrieNode*> children;
        bool isEnd = false;
};

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for(char c : word){
            if(!curr->children.count(c))
                curr->children[c] = new TrieNode();
            curr = curr->children[c];
        }
        curr->isEnd = true;
    }

    bool searchDeep(TrieNode* curr, string subWord){
        if(!subWord.length()){
            if(curr->isEnd)
                return true;
            return false;
        } 
        int n = subWord.length();
        
        for(int i = 0; i < n; i++){
            char c = subWord[i];
            if(c == '.'){
                for(auto it = curr->children.begin(); it != curr->children.end(); it++){
                    if(searchDeep(it->second, subWord.substr(i + 1))){
                        return true;
                    }
                }
                return false;
            } else {
                if(!curr->children.count(c))
                    return false;
                curr = curr->children[c];
            }
        }
        if(curr->isEnd)
            return true;
        return false;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        int n = word.length();
        return searchDeep(curr, word);
    }
};
