class Solution {
public:
    using pii = pair<int, int>;

    int minCost(int n, vector<vector<int>>& edges) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        unordered_map<int, vector<pii>> adj;

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, 2 * w});
        }

        priority_queue<pii, vector<pii>, greater<pii>> pq;

        vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (node == n - 1)
                return dist[n - 1];

            if (d > dist[node]) continue;

            for (auto &p : adj[node]) {
                int adjNode = p.first;
                int w = p.second;

                if (d + w < dist[adjNode]) {
                    dist[adjNode] = d + w;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        return -1;
    }
};
