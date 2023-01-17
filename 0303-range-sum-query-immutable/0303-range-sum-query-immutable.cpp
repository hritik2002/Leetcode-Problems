class NumArray {
public:
    vector<int> tree;
    int size;
    
    NumArray(vector<int>& nums) {
        int n = nums.size();
        size = n;
        tree.resize(n + 1, 0);
        
        for(int i = 0; i < n; i++) {
            int j = i + 1;
            int val = nums[i];
            int toAdd = val - (sum(j) - sum(j - 1));
            
            while(j <= size) {
                tree[j] += toAdd;
                j += (j & -j);
            }
        }
    }
    
    int sum(int index) {
        int ans = 0;
        
        while(index > 0) {
            ans += tree[index];
            index -= (index & -index);
        }
        
        return ans;
    }
    
    int sumRange(int left, int right) {
        return sum(right + 1) - sum(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */