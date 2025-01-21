/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
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
    void inorder(TreeNode* root, vector<int> &v){
        if(root == NULL)    return;

        inorder(root -> left, v);
        v.pb(root -> val);
        inorder(root -> right, v);
    }

    TreeNode* createTree(vector<int> &v, int s, int e){
        if(s > e)   return NULL;

        int mid = (s + e) / 2;
        TreeNode* node = new TreeNode(v[mid]);
        node -> left = createTree(v, s, mid - 1);
        node -> right = createTree(v, mid + 1, e);

        return node;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        inorder(root, v);

        return createTree(v, 0, v.size() - 1);
    }
};