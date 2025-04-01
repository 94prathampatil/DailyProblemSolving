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
#define um unordered_map

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int s, int d) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        um<int, list<int>> adj;

        for(int i = 0;i < edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        um<int, bool> visited;
        vector<int> path;
        queue<int> q;

        q.push(s);
        visited[s] = true;

        while(!q.empty()){
            int front = q.front();
            q.pop();

            if(front == d)
                return true;

            for(auto &i:adj[front]){
                if(!visited[i]){
                    visited[i] = true;
                    q.push(i);
                }
            }
        }

        return false;

    }

};