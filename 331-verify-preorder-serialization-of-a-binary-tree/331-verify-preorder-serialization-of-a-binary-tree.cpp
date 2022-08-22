class Solution {
public:
    bool isSerialized(string &preorder, int &index, int size) {
        if(index >= size || preorder[index] == '#') {
            return true;
        }
        
        
        while(index < size && preorder[index] != ',') {
            index++;
        }
        index++;
        
        bool left = isSerialized(preorder, index, size);
        
        while(index < size && preorder[index] != ',') {
            index++;
        }
        index++;
        
        if(index >= size) {
            return false;
        }
        
        
        bool right = isSerialized(preorder, index, size);
        
        
        return left && right;
    }
    
    bool isValidSerialization(string preorder) {
        int index = 0, size = preorder.length();
        
        bool child = isSerialized(preorder, index, size);
        
        if(index < size - 1) {
            return false;
        }
        
        return child;
    }
};

