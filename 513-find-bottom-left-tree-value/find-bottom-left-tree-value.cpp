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
    int findBottomLeftValue(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        if(!root -> left && !root -> right) 
            return root -> val;


        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;

        while(!q.empty()){
            int n = q.size();
            bool left = false;

            for(int i = 0;i < n;i++){
                TreeNode* node = q.front();
                q.pop();

                if(left == false){
                    ans = node -> val;
                    left = true;
                }

                if(node -> left)
                    q.push(node -> left);

                if(node -> right)
                    q.push(node -> right);
            }
        }

        return ans;
    }
};