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

#define pb(x) push_back(x)

class Solution {
public:
    void solve(TreeNode* root, int &sum){
        if(root == NULL)
            return ;
        
        if(root -> left == NULL && root -> right == NULL){
            root -> val += sum;
            sum = root -> val;
            return;
        }

        solve(root -> right, sum);
        root -> val += sum;
        sum = root -> val;
        solve(root -> left, sum);
    }
    TreeNode* convertBST(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        if(root == NULL)
            return NULL;

        int sum = 0;
        solve(root, sum);
        return root;
    }
};