class trie {
    bool isRoot = false;
    trie* l[26] = {};
public:
    void insert(string& word, int ch, int sz) {
        isRoot |= ch == sz;
        if (!isRoot) { // stop at the shortest root.
            if (l[word[ch] - 'a'] == nullptr) l[word[ch] - 'a'] = new trie();
            l[word[ch] - 'a']->insert(word, ch + 1, sz);
        }
    }
    int root(string& word, int st, int ch, int sz) {
        if (st + ch == sz || word[st + ch] == ' ' || this->isRoot) return ch;
        if (l[word[st + ch] - 'a'] == nullptr) { // root was not found
            while (st + ch < sz && word[st + ch] != ' ') ++ch; // skipping the entire word
            return ch;
        }
        return l[word[st + ch] - 'a']->root(word, st, ch + 1, sz);
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dict, string snt) {
        trie t;
        string res;
        for (auto s : dict) t.insert(s, 0, s.size());
        for (int i = 0; i < snt.size(); ) {
            if (snt[i] == ' ') res += snt[i++];
            auto chars = t.root(snt, i, 0, snt.size());
            res += snt.substr(i, chars);
            for (i += chars; i < snt.size() && snt[i] != ' '; ++i);
        }
        return res;
    }
};
