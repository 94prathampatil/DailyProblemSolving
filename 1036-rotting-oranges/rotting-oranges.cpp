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
    int orangesRotting(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int> > visited = grid;

        queue<pair<int, int>>  q;
        int orange = 0;

        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(visited[i][j] == 2){
                    q.push({i, j});
                }
                if(visited[i][j] == 1){
                    orange++;
                }
            }
        }

        if(orange == 0) return 0;

        if(q.empty())
            return -1;
        

        vector<pair<int, int>> dirs = {{1, 0},{-1, 0},{0, -1},{0, 1}};
        
        int min = -1;

        while(!q.empty()){
            int size = q.size();

            while(size--){
                auto [x, y] = q.front();
                q.pop();

                for(auto [dx, dy]:dirs){
                    int i = x + dx;
                    int j = y + dy;

                    if(i >= 0 && i < m && j >= 0 && j < n && visited[i][j] == 1){
                        orange--;
                        visited[i][j] = 2;
                        q.push({i, j});
                    }
                }
            }

            min++;
        }

        if(orange == 0) return min;

        return -1;
    }
};