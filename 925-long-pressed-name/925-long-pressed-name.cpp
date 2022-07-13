class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0 ;
        int name_len = name.length(), typed_len = typed.length();
        while(i<name_len && j<typed_len){
            if(name[i]==typed[j]){
                i++;
            }else if(i<=0 || (i>0 && name[i-1] != typed[j]))
                return false;
            j++;
        }
        if(i != name_len)return false;
        while(j<typed_len){
            if(name[i-1] != typed[j])return false;
            j++;
        }
        return true;
        
    }
};