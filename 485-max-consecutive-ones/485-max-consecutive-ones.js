/**
 * @param {number[]} nums
 * @return {number}
 */
var findMaxConsecutiveOnes = function(nums) {
    let ans = 0, count = 0;
    
    if(nums[0] == 1) count++;
    
    if(ans < count) {
            ans = count;
    }
    
    for(let i = 1; i < nums.length; i++) {
        if(nums[i] == nums[i - 1] && nums[i] == 1) {
            count++;
        }else if(nums[i] == 1){
            count = 1;
        }else count = 0;
        
        if(ans < count) {
            ans = count;
        }
    }
    
    return ans;
};