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
    void solve(TreeNode* root, int &target, int sum, vector<int> temp, vector<vector<int>> &ans){
        if(!root)   return;

        sum += root -> val;
        temp.push_back(root -> val);

        if(isLeaf(root) && sum == target){
            ans.push_back(temp);
            return;
        }

        solve(root -> left, target, sum, temp, ans);
        solve(root -> right, target, sum, temp, ans);

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        if(root == NULL)    return {};

        vector<vector<int>> ans;
        vector<int> temp;
        int sum = 0;

        solve(root, targetSum, sum, temp, ans);

        return ans;
    }
};
