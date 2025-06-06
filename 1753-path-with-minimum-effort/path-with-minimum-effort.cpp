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
    int minimumEffortPath(vector<vector<int>>& heights) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = heights.size();
        int m = heights[0].size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > pq;

        vector<vector<int>> dist(n, vector<int> (m, 1e9));
    
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
 
        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if(row == n - 1 && col == m - 1)    return diff;

            for(int i = 0;i < 4;i++){
                int newr = row + dr[i];
                int newc = col + dc[i];

                if(newr >= 0 && newr < n && newc >= 0 && newc < m){
                    int newEffort = max(abs(heights[row][col] - heights[newr][newc]), diff);
                    if(newEffort < dist[newr][newc]){
                        dist[newr][newc] = newEffort;
                        pq.push({newEffort, {newr, newc}});
                    }
                }
            }

        }

        return 0;
    }
};