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
    vector<vector<int>> levelOrder(TreeNode* root){
        vector<vector<int>> level;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            vector<int> ans;

            int size = q.size();

            for(int i = 0;i < size;i++){
                TreeNode* node = q.front();
                q.pop();
                ans.push_back(node -> val);

                if(node -> left)    q.push(node -> left);
                if(node -> right)   q.push(node -> right);
            }

            level.push_back(ans);
        }

        return level;
    }
    int maxLevelSum(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<vector<int>> levels = levelOrder(root);
        int l = 0;
        int ans = 0;
        int maxi = INT_MIN;

        for(auto &level : levels){
            int sum = accumulate(level.begin(), level.end(), 0);
            
            if(sum > maxi){
                maxi = sum;
                ans = l;
                l += 1;
            }           
            else{
                l += 1;
            }
        }

        return ans + 1;
    }
};