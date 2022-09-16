/**
 * @param {number[]} num
 * @param {number} k
 * @return {number[]}
 */
var addToArrayForm = function(num, k) {
    const num_to_add = k.toString().split("");
    
    let i = num.length - 1, j = num_to_add.length - 1;
    let carry = 0;
    
    while(i >= 0 && j >= 0) {
        const sum = (num[i] + Number(num_to_add[j]) + carry);
        carry = Math.floor((sum) / 10);
        num[i] = sum % 10;
        
        i--;
        j--;
    }
    
    while(i >= 0 && carry) {
        const sum = (num[i] + carry);
        carry = Math.floor((sum) / 10);
        num[i] = sum % 10;
        
        i--;
    }
    
    while(j >= 0) {
        const sum = (Number(num_to_add[j]) + carry);
        carry = Math.floor((sum) / 10);
        num = [sum % 10, ...num];
        
        j--;
    }
    
    if(carry) {
        num = [carry, ...num];
    }
    
    return num;
};