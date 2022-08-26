/**
 * @param {string[]} cpdomains
 * @return {string[]}
 */
var subdomainVisits = function(cpdomains) {
    let ans = [];
    let set = {};
    
    cpdomains.map(str => {
        let arr = str.split(" ");
        let res = arr[1];
        let reqArr = res.split(".");
        let temp = "";
        
        for(let i = reqArr.length - 1; i>=0; i--) {
            if(temp.length == 0) {
                temp = reqArr[i];
            }else {
                temp = reqArr[i] + '.' + temp;
            }
            
            if(Number(set[temp]))
                set[temp] = Number(set[temp]) + Number(arr[0]);
            else set[temp] = Number(arr[0]);
        }
        
    })
    
    for(let key in set) {
            ans.push(set[key] + " " + key);
        }
    
    return ans;
};