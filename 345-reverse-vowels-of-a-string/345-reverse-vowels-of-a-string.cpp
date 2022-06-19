class Solution {
public:
    string reverseVowels(string s) {
        int n= s.length();
        int i=0,j=n-1;
        set<char>st;
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');
        st.insert('A');
        st.insert('E');
        st.insert('O');
        st.insert('I');
        st.insert('U');
        string ans = "";
        while(i<j){
            while(i<j && !st.count(s[i]))i++;
            while(i<j && !st.count(s[j]))j--;
            if(i>=j)break;
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            ans = s ;
            s = ans;
            i++;
            j--;
        }
        return s;
    }
};