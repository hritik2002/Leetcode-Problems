class TrieNode {
public:
    int countWords;                // number of words that end here
    int countStarts;                // number of words that pass through this node
    TrieNode* children[26] = {NULL};      // children nodes
    TrieNode(){
        countWords = 0;
        countStarts = 0;
    }
};

class Trie {
public:
    TrieNode* root;
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* temp = root;
        int n = word.size();
        for(int i = 0; i < n; i++){
		// if this character is not present in trie, we add it
            if(temp->children[word[i]-'a'] == NULL){
                temp->children[word[i]-'a'] = new TrieNode();
            }
            temp = temp->children[word[i]-'a'];
			// increment the count of words starting with/passing through this character
            temp->countStarts++;
        }
		// increment word counter for the last character
        temp->countWords++;
    }
    
    int countWordsEqualTo(string word) {
        TrieNode* temp = root;
        int n = word.size();
		// base case
        if(n == 0){
            return 0;
        }
        for(int i = 0; i < n; i++){
		    // if this character is not present in trie, there are no matching words possible
            if(temp->children[word[i]-'a'] == NULL){
                return 0;
            } else {
			// move to the next character
               temp = temp->children[word[i]-'a'];
            }
        }
		// return the count of words ending with the last character
        return temp->countWords;
        
    }
    
    int countWordsStartingWith(string prefix) {
        TrieNode* temp = root;
        
        int n = prefix.size();
        if(n == 0){
            return 0;
        }
        for(int i = 0; i < n; i++){
		// if this character is not present, there are no matching words possible.
		// NOTE: Because of ERASE operation, we might have nodes which are no longer
		// present in any word's path, so we have to check countStarts
            if(temp->children[prefix[i]-'a'] == NULL || 
               temp->children[prefix[i]-'a']->countStarts == 0){
                return 0;
            } else {
               temp = temp->children[prefix[i]-'a'];
            }
        }
		// return the count of words passing through the last character
        return temp->countStarts;
    }
    
    void erase(string word) {
        TrieNode* temp = root;
        int n = word.size();
        for(int i = 0; i < n; i++){
		    // decrement the counter for words which pass through this node
            temp->children[word[i]-'a']->countStarts--;
            temp = temp->children[word[i]-'a'];
        }
		// decrement the word counter for the last character
        temp->countWords--;
    }
};
