class SegmentTree {
    vector<int> tree;
    int n;
public:
    SegmentTree(vector<int>& nums) {
        n = nums.size();
        tree = vector<int>(4*n);
        
        build(nums, 1, 0, n - 1);
    }
    
    int sum(int l, int r) {
        return sum(1, 0, n - 1, l, r);
    }
    
    void update(int pos, int val) {
        update(1, 0, n - 1, pos, val);
    }
    
private:
    void build(vector<int> &nums, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = nums[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(nums, v*2, tl, tm);
            build(nums, v*2+1, tm+1, tr);
            tree[v] = tree[v*2] + tree[v*2+1];
        }
    }
    
    int sum(int v, int tl, int tr, int l, int r) {
        if (l > r) 
            return 0;
        if (l == tl && r == tr) {
            return tree[v];
        }
        int tm = (tl + tr) / 2;
        return sum(v*2, tl, tm, l, min(r, tm))
               + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
    }
    
    void update(int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr) {
            tree[v] = new_val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v*2, tl, tm, pos, new_val);
            else
                update(v*2+1, tm+1, tr, pos, new_val);
            tree[v] = tree[v*2] + tree[v*2+1];
        }
    }
};

class NumArray {
    SegmentTree tree;
public:
    NumArray(vector<int>& nums): tree(nums) {}
    
    void update(int index, int val) {
        tree.update(index, val);
    }
    
    int sumRange(int left, int right) {
        return tree.sum(left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */