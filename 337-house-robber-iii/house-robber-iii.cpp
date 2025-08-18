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
class Solution {
public:
    pair<int, int> solve(TreeNode* &root){
        if(!root)   return {0, 0};

        auto left = solve(root -> left);
        auto right = solve(root -> right);

        int rob = root -> val + left.second + right.second;
        int notRob = max(left.first, left.second) + max(right.first, right.second);

        return {rob, notRob};
    }
    int rob(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        auto ans = solve(root);
        return max(ans.first, ans.second);

        return 0;
    }
};