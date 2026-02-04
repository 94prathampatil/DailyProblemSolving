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
    unordered_map<int, int> mp;
    void solve(TreeNode* root){
        if(root == NULL){
            return ;
        }

        mp[root -> val]++;

        solve(root -> left);
        solve(root -> right);
    }
    vector<int> findMode(TreeNode* root) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        if(!root -> right && !root -> left)
            return {root -> val};

        vector<int> ans;
        solve(root);
        int freq = 0;

        for(auto &i : mp){
            freq = max(i.second, freq);
        }

        for(auto &i : mp){
            if(i.second == freq)
                // cout << i.first << " " << i.second << endl;
                ans.push_back(i.first);
        }

        return ans;
    }
};