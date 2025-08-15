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
    bool isLeaf(TreeNode* root){
        return (root && !root -> left && !root -> right);
    }

    void solve(TreeNode* root, int num, int &ans){
        if(!root) return;

        num = num * 10 + root -> val;

        if(isLeaf(root))
            ans += num;

        solve(root -> left, num, ans);
        solve(root -> right, num, ans);

    }
    int sumNumbers(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        int ans = 0;
        solve(root, 0, ans);
        return ans;
    }   
};