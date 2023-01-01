/**
 * @param {string} pattern
 * @param {string} s
 * @return {boolean}
 */
var wordPattern = function(pattern, s) {
    let obj = {};
    let word_to_letter = {}
    s = s.split(" ");
    if(s.length != pattern.length) {
        return false;
    }
    
    for(let i = 0; i < pattern.length; i++) {
        if(!obj[pattern[i]]) {
            if(word_to_letter[s[i]]) {
                return false;
            }
            
            word_to_letter[s[i]] = pattern[i];
            obj[pattern[i]] = s[i];
        }else {
            
            if(obj[pattern[i]] != s[i]) {
                return false;
            }
        }
    }
    
    return true;
};