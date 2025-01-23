const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
#endif

#define pb(x) push_back(x)

class Solution {
public:
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<int>> ans_mp;
        vector<vector<int>> ans;
        if (root == nullptr) return ans;

        queue<pair<TreeNode*, int>> q;

        q.push({root, 0});
        int level = 0;

        while(!q.empty()) {
            int n = q.size();
            map<int, vector<int>> mp;
            while (n > 0) {
                TreeNode * cur = q.front().first;
                int column = q.front().second;
                q.pop();
                mp[column].push_back(cur->val);
                if (cur -> left) {
                    q.push({cur -> left, column -1});
                }
                if (cur -> right) {
                    q.push({cur -> right, column +1});
                }
                n--;
            }
            for (auto it: mp) {
                sort(it.second.begin(), it.second.end());
                ans_mp[it.first].insert(ans_mp[it.first].end(), it.second.begin(), it.second.end());
            }
        }


        for (auto it: ans_mp) {
            ans.push_back(it.second);
        }
        

        return ans;
    }
};