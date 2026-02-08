class NumArray {
public:
    vector<int> seg;
    int n;

    NumArray(vector<int>& nums) {
        n = nums.size();
        seg.resize(4 * n);
        if (n > 0)
            buildTree(0, 0, n - 1, nums);
    }

    void buildTree(int i, int l, int r, vector<int>& nums) {
        if (l == r) {
            seg[i] = nums[l];
            return;
        }

        int mid = l + (r - l) / 2;
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;

        buildTree(leftChild, l, mid, nums);
        buildTree(rightChild, mid + 1, r, nums);

        seg[i] = seg[leftChild] + seg[rightChild];
    }

    void update(int index, int val, int i = 0, int l = 0, int r = -1) {
        if (r == -1) r = n - 1;

        if (l == r) {
            seg[i] = val;
            return;
        }

        int mid = l + (r - l) / 2;
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;

        if (index <= mid)
            update(index, val, leftChild, l, mid);
        else
            update(index, val, rightChild, mid + 1, r);

        seg[i] = seg[leftChild] + seg[rightChild];
    }

    int query(int ql, int qr, int i, int l, int r) {
        if (r < ql || l > qr)
            return 0;

        if (ql <= l && r <= qr)
            return seg[i];

        int mid = l + (r - l) / 2;

        return query(ql, qr, 2 * i + 1, l, mid) +
               query(ql, qr, 2 * i + 2, mid + 1, r);
    }

    int sumRange(int left, int right) {
        if (n == 0) return 0;
        return query(left, right, 0, 0, n - 1);
    }
};
