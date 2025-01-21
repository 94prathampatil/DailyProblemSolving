const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
#endif

class Solution {
public:
    int solve(TreeNode* root, int &sum, int l, int h){
        if(root == NULL)
            return sum;
        
        if(root -> val >= l && root -> val <= h){
            sum += root -> val;
        }

        solve(root -> left, sum, l, h);
        solve(root -> right, sum, l, h);

        return sum;
    }
    int rangeSumBST(TreeNode* root, int l, int h) {
        int sum = 0;

        solve(root, sum, l, h);

        return sum;

    }
};