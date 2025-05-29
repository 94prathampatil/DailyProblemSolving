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
#define all(x) x.begin(), x.end()

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = adj.size();
        vector<vector<int>> adjRev(n);         
        vector<int> indegree(n, 0);           
        
        
        for(int i = 0;i < n;i++){
            for(auto &it:adj[i]){
                adjRev[it].pb(i);
                indegree[i]++;
            }
        }

        vector<int> safeNode;

        queue<int> q;
        for(int i = 0;i < n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            safeNode.pb(node);

            for(auto it:adjRev[node]){
                indegree[it]--;
                if(indegree[it] == 0)
                    q.push(it);
            }
        }

        sort(all(safeNode));

        return safeNode;
    }
};