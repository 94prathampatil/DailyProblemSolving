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
    int stringToBin(string s){
        int res = 0;

        for(auto c : s){
            res = res * 2 + (c - '0');
        }

        return res;
    }
    int solve(TreeNode* root, string bin){
        if(root == NULL)    return 0;

        bin += to_string(root -> val);

        if(!root -> left && !root -> right){
            return stringToBin(bin);
        }

        return solve(root -> left, bin) + solve(root -> right, bin);
    }
    int sumRootToLeaf(TreeNode* root) {
        return solve(root, "");
    }
};