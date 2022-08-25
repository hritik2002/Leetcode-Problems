class TrieNode {
    public: 
    vector<TrieNode* > children;
    
    TrieNode() {
        children.resize(2, NULL);
    }
};

class Solution {
public:
    TrieNode* root = new TrieNode();
    int findMaximumXOR(vector<int>& nums) {
        // insert
        int n = nums.size();
        
        for(int i = 0; i < n; i++) {
            insert(nums[i]);
        }
        
        int maxVal = 0;
        
        for(int i = 0; i < n; i++) {
            maxVal = max(maxVal, getXOR(nums[i]));
        }
        
        return maxVal;
    }

    int getXOR(int n) {
        int max = 0;
        TrieNode* curr = root;
        
        for(int i = 31; i >= 0; i--) {
            int k = (n >> i) & 1;
            
            if(k == 1 && curr -> children[0]) {
                max = max | (1 << i);
                k = 0;
            }else if(k == 0 && curr -> children[1]) {
                k = 1;
                max = max | (1 << i);
            }
            
            curr = curr -> children[k];
        }
        
        return max;
    }

    void insert(int n) {
        TrieNode* curr = root;
        
        for(int i = 31; i >= 0; i--) {
            int k = (n >> i) & 1;
            
            if(curr -> children[k] == NULL)
                curr -> children[k] = new TrieNode();
            
            curr = curr -> children[k];
        }
    }
};