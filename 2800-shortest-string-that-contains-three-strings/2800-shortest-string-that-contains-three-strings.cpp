class Solution {
public:
    string solve(string &a, string &b) {
        if(a.find(b) != string::npos) {
            return a;
        }
        if(b.find(a) != string::npos) {
            return b;
        }
        
        string merged1 = a + b;
        int len1 = a.length(), len2 = b.length();
        
        for(int i = min(len1, len2) - 1; i >= 0; i--) {
            if(a.substr(len1 - i - 1) == b.substr(0, i + 1)) {
                merged1 = a + b.substr(i + 1);
                break;
            }
        }
        
        string merged2 = b + a;
        
        for(int i = min(len1, len2) - 1; i >= 0; i--) {
            if(b.substr(len2 - i - 1) == a.substr(0, i + 1)) {
                merged2 = b + a.substr(i + 1);
                break;
            }
        }
        
        if(merged1.length() < merged2.length()) {
            return merged1;
        }else if(merged1.length() > merged2.length()) {
            return merged2;
        }
        
        return min(merged1, merged2);
    }
    
    static bool cmp(string &a, string &b) {
        if(a.length() == b.length()) {
            return a < b;
        }
        
        return a.length() < b.length();
    }
    
    string minimumString(string a, string b, string c) {
        string str1 = solve(a, b);
        string str2 = solve(a, c);
        string str3 = solve(b, c);
        
        string ans1 = solve(str1, c);
        string ans2 = solve(str2, b);
        string ans3 = solve(str3, a);
        
        vector<string> arr = {ans1, ans2, ans3};
        
        sort(arr.begin(), arr.end(), cmp);
        
        return arr[0];
    }
};