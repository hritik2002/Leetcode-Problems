/**
 * @param {number} n
 * @return {number[]}
 */
var countBits = function(n) {
    let arr = [];
    
    for(let i = 0; i <= n; i++) {
        let count = 0;
        i.toString(2).split("").map(x => '1' === x ? count++: "")
        let ele = count;
        arr.push(ele);
    }
    
    return arr;
};