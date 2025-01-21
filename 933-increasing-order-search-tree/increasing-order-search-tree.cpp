class Solution {
public:
    void solve(TreeNode* root, TreeNode* &prev){
        if(root == NULL)    return;

        solve(root -> left, prev);

        root -> left = NULL;
        prev -> right = root;
        prev = root;

        solve(root -> right, prev);
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* temp = new TreeNode(0);
        TreeNode* prev = temp;

        solve(root, prev);

        return temp -> right;
    }
};