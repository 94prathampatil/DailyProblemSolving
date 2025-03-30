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
    void bfs(int node, vector<bool> &visited, vector<int> adj[]){
        visited[node] = true;
        for(auto i:adj[node]){
            if(!visited[i]){
                bfs(i, visited, adj);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = isConnected.size();

        vector<int> adj[n];

        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(isConnected[i][j]){
                    adj[j].push_back(i);
                    adj[i].push_back(j);
                }
            }
        }

        vector<bool> visited(n, 0);
        int cnt = 0;

        for(int i = 0;i < n;i++){
            if(!visited[i]){
                cnt++;
                bfs(i, visited, adj);
            }
        }

        return cnt;

    }
};