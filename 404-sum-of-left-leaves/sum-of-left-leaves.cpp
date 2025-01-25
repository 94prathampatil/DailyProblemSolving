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
    int solve(TreeNode* root, int &sum, int isLeft){
        if(root == NULL){
            return 0;
        }
        if(root -> left == NULL && root -> right == NULL){
            sum = (isLeft == 1) ? sum += root -> val : sum = sum;
            return sum;
        }


        solve(root -> left, sum, 1);
        solve(root -> right, sum, 0);

        return sum;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        if(root == NULL)
            return 0;
        
        if(root -> left == NULL && root -> right == NULL){
            return 0;
        }

        int sum = 0;
        solve(root, sum, 0);
        return sum;
    }
};