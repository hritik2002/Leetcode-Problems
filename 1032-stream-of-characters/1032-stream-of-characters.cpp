class TrieNode {
    public: 
        bool isWord;
        vector<TrieNode*> children;
    
    TrieNode() {
        isWord = false;
        children.resize(27, NULL);
    }
};

class StreamChecker {
public:
    TrieNode* root;
    vector<char> stream;
    StreamChecker(vector<string>& words) {
        root =  new TrieNode();
        for(string word : words) {
            reverse(word.begin(), word.end());
            
            // insert the reversed word
            TrieNode* node = root;
            
            for(char ch : word) {
                if(node->children[ch - 'a'] == NULL) {
                    node->children[ch - 'a'] = new TrieNode();
                }
                
                node = node->children[ch - 'a'];
            }
            node->isWord = true;
        }
    }
    
    bool query(char letter) {
        // insert in front
        stream.insert(stream.begin(), letter);
        
        TrieNode* node = root;
        
        for(char ch : stream) {
            if(node->children[ch - 'a'] == NULL) {
                return false;
            }
            if(node->children[ch - 'a']->isWord) {
                return true;
            }
            
            node = node->children[ch - 'a'];
        }
        
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */