class TrieNode {
    public:
        vector<TrieNode*> children;
        bool is_word;
        char val;
    
    TrieNode(char _val) {
        is_word = false;
        val = _val;
        children.resize(26, NULL);
    }
};
class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode('a');
    }
    
    void addWord(string word) {
        int len = word.length();
        TrieNode* curr = root;
        
        for(int i = 0; i < len; i++) {
            
            if(curr->children[word[i] - 'a'] == NULL)
                curr->children[word[i] - 'a'] = new TrieNode(word[i]);
            
            curr = curr->children[word[i] - 'a'];
        }
        
        curr->is_word = true;
    }
    
    bool search(string word) {
        int len = word.size();
        TrieNode* node = root;
        
        return search(word.c_str(), node);
    }
    
    bool search(const char* word, TrieNode* node) {
        for(int i = 0; word[i] && node; i++) {
            if(word[i] != '.') {
                node = node -> children[word[i] - 'a'];
            }else {
                TrieNode* temp = node;
            
                for(int j = 0; j < 26; j++) {
                    node = temp -> children[j];
                    
                    if(search(word + i + 1, node)) {
                        return true;
                    }
                }
            }
        }
        
        return node && node -> is_word;
    }

};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */