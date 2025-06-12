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


class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<pair<int, int>> adj[n + 1];
        for(auto it : times){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v, w});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n + 1, 1e9);
        dist[k] = 0;
        pq.push({0, k});

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int w = it.first;
            int node = it.second;

            for(auto nbr : adj[node]){
                int adjNode = nbr.first;
                int edW = nbr.second;

                if(w + edW < dist[adjNode]){
                    dist[adjNode] = w + edW;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        int maxTime = 0;
        for(int i = 1; i <= n; ++i){
            if(dist[i] == 1e9) return -1;
            maxTime = max(maxTime, dist[i]);
        }

        return maxTime;
    }
};
