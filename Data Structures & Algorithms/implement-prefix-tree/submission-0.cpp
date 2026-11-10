class PrefixTree {
private:
    map<char, PrefixTree*> tree;
    bool isEnd = false;
public:
    PrefixTree() {
    }
    
    void insert(string word) {
        int index = 0;
        char c = word[index];
        PrefixTree* node = this;
        if(tree.count(c)){
            while(index < word.length() && node->tree.count(c)){
                node = node->tree[c];
                c = word[++index];
            }
        }
        while(index < word.length()){
            PrefixTree* newChar = new PrefixTree();
            node->tree[c] = newChar;
            node = newChar;
            c = word[++index];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        int index = 0;
        char c = word[index];
        PrefixTree* node = this;
        while(index < word.length() && node->tree.count(c)){
            node = node->tree[c];
            c = word[++index];
        }
        if(index == word.length() && node->isEnd)
            return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        int index = 0;
        char c = prefix[index];
        PrefixTree* node = this;
        while(index < prefix.length() && node->tree.count(c)){
            node = node->tree[c];
            c = prefix[++index];
        }
        if(index == prefix.length())
            return true;
        return false;
    }
};
