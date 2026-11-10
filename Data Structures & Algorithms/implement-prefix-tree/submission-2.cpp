class TrieNode {
    public:
        unordered_map<char, TrieNode*>children;
        bool isEnd = false;
};

class PrefixTree {
public:
    TrieNode *root;

    PrefixTree() {
        root = new TrieNode();    
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(char c : word){
            if(!curr->children.count(c))
                curr->children[c] = new TrieNode();
            curr = curr->children[c];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(char c : word){
            if(!curr->children.count(c))
                return false;
            curr = curr->children[c];
        }
        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(char c : prefix){
            if(!curr->children.count(c))
                return false;
            curr = curr->children[c];
        }
        return true;
    }
};
