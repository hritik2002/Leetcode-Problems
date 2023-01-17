class NumArray {
public:
    vector<int> tree;
    int size;
    NumArray(vector<int>& nums) {
        int n = nums.size();
        tree.resize(n + 1, 0);
        this->size = n;
        
        for(int i = 0; i < n; i++) {
            update(i, nums[i]);
        }
    }
    
    void update(int i, int val) {
        i++;
        val -= getSum(i) - getSum(i-1);
        
        while(i <= size) {
            tree[i] += val;
            
            i += RSB(i);
        }

    }
    
    int sumRange(int left, int right) {
        return getSum(right + 1) - getSum(left);
    }
    
    int getSum(int index) {
        int sum = 0;
        
        while(index > 0) {
            sum += tree[index];
            
            index -= RSB(index);
        }
        return sum;
    }
    
    int RSB(int x) {
        return x & -x;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */