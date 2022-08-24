class TrieNode {
    public: 
        TrieNode* root;
        bool is_word;
        vector<TrieNode*> children;
        char value;
    
    TrieNode(char val) {
        value = val;
        children.resize(26, NULL);
        is_word = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('a');
    }
    
    void insert(string word) {
        int size = word.length();
        TrieNode* curr = root;
        
        for(int i = 0; i < size; i++) {
            int k = word[i] - 'a';
            
            if(curr->children[k] == NULL) {
                curr->children[k] = new TrieNode(word[i]);
            }
            if(i == size - 1) {
                curr->children[k]->is_word = true;
            }
            
            curr = curr->children[k];
        }
        
    }
    
    bool search(string word) {
        int size = word.length();
        TrieNode* curr = root;
        
        for(int i = 0; i < size; i++) {
            int k = word[i] - 'a';
            curr = curr->children[k];
            
            if(curr == NULL) {
                return false;
            }
            
        }
        
        return curr->is_word;
    }
    
    bool startsWith(string prefix) {
        int size = prefix.length();
        TrieNode* curr = root;
        
        for(int i = 0; i < size; i++) {
            int k = prefix[i] - 'a';
            curr = curr->children[k];
            
            if(curr == NULL) {
                return false;
            }
            
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */