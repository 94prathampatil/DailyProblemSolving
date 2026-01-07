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

#define  ll long long
class Solution {
public:
    ll totalSum = 0;
    ll maxProd = 0;
    static const int MOD = 1e9 + 7;

    ll dfs(TreeNode* root) {
        if (!root) return 0;

        ll left = dfs(root->left);
        ll right = dfs(root->right);
        ll subTreeSum = root->val + left + right;

        maxProd = max(maxProd, subTreeSum * (totalSum - subTreeSum));

        return subTreeSum;
    }

    int maxProduct(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        totalSum = dfsSum(root);
        dfs(root);

        return maxProd % MOD;
    }

private:
    ll dfsSum(TreeNode* root) {
        if (!root) return 0;
        return root->val + dfsSum(root->left) + dfsSum(root->right);
    }
};
