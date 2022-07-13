class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0 ;
        int name_len = name.length(), typed_len = typed.length();
        while(j<typed_len){
            if(i<name_len && name[i]==typed[j]){
                i++;
                j++;
            }else{
                if(i<=name_len && i>0 && name[i-1] == typed[j]);
                else{
                    return false;
                }
                j++;
            }
        }
        if(i != name_len)return false;
        return true;
        
    }
};