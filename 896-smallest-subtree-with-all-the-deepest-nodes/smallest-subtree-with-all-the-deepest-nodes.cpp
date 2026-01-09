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
    int maxDepth = 0;
    int dfs(TreeNode* root, int depth, TreeNode* &ans){
        if(!root)   return depth;

        int left = dfs(root -> left, depth + 1, ans);
        int right = dfs(root -> right, depth + 1, ans);

        int currDepth = max(left, right);
        maxDepth = max(maxDepth, currDepth);

        if(left == right && left == maxDepth){
            ans = root;
        }

        return currDepth;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        if(!root)   return NULL;

        TreeNode* ans = NULL;

        dfs(root, 0, ans);
        return ans;
    }
};