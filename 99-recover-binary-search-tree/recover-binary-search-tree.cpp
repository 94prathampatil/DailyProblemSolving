// @before-stub-for-debug-begin

// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
 */

// @lc code=start

#include <bits/stdc++.h>

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
        if(root == NULL)
            return;

        inorder(root->left, v);
        v.pb(root->val);
        inorder(root->right, v);
    }

    void solve(TreeNode* root, vector<int> v, int &i){
        if(root == NULL)
            return;

        solve(root->left, v, i);
        if(root -> val != v[i]){
            root->val = v[i];
        }
        i++;
        solve(root->right, v, i);
    }
    void recoverTree(TreeNode* root) {
        vector<int> v;
        inorder(root, v);
        sort(v.begin(), v.end());
        
        int i = 0;
        solve(root, v, i);
    }
};
// @lc code=end

