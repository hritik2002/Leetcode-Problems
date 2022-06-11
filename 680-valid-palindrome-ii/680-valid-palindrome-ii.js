let helper = (s,i,j)=>{
    while(i<j){
        if(s[i]!=s[j])return false;
        i++;
        j--;
    }
    return true;
}
var validPalindrome = function(s) {
    let i=0 , j = s.length-1;
    while(i<j){
        if(s[i]!=s[j]){
            return helper(s,i+1,j) || helper(s,i,j-1);
        }
        i++;
        j--;
    }
    return true;
};