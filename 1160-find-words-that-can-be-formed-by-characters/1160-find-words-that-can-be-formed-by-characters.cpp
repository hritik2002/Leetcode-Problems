class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> arr1(26, 0);
        int l = chars.length(), n = words.size();
        int count = 0;
        
        for(int i = 0; i < l; i++) {
            arr1[chars[i] - 'a']++;
        }
        
        for(int i = 0; i < n; i++) {
            vector<int> arr2(26, 0);
            
            for(auto c : words[i]) {
                arr2[c - 'a']++;
            }
            
            bool flag = true;
            
            for(int j = 0; j < 26; j++) {
                if(arr1[j] < arr2[j]) {
                    flag = false;
                    break;
                }
            }
            
            if(flag) {
                count += words[i].length();
            }
        }
        
        return count;
    }
};