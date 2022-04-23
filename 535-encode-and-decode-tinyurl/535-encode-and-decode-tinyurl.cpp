class Solution {
    map<string,string>store;
    int count ;
public:
    Solution(){
        count = 0 ;
    }
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string ans =  "https://tinyurl.com/";
        ans += to_string(count);
        store[ans] = longUrl ;
        return ans;
        
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return store[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));