class Trie{
  public:
    vector<Trie*> child;
    int freq;

    Trie() {
        child.resize(26, NULL);
        freq = 0;
    }

};

class Solution {
public:
    Trie* root;
    
    int getScore(string word) {
        Trie* node = root;
        int count = 0;
        
        for(auto ch : word) {
            count += node->child[ch - 'a']->freq;
            node = node->child[ch - 'a'];
        }
        
        return count;
    }
    void insert(string word) {
        Trie* node = root;
        
        for(auto ch : word) {
            if(node->child[ch - 'a'] == NULL) {
                node->child[ch - 'a'] = new Trie();
            }
            
            node->child[ch - 'a']->freq++;
            node = node->child[ch - 'a'];
        }
        
        return;
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        root = new Trie();
        vector<int> ans;
        
        for(auto word : words) {
            insert(word);
        }
        
        for(auto word : words) {
            ans.push_back(getScore(word));
        }
        
        return ans;
    }
};