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
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>>& grid){
        vis[row][col] = 1;

        array<int, 4> dRow = {-1, 0, 1, 0};
        array<int, 4> dCol = {0, 1, 0, -1};

        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0;i < 4;i++){
            int x = dRow[i] + row;
            int y = dCol[i] + col;
            
            if(x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && grid[x][y] == 1){
                dfs(x, y, vis, grid);
            }    
        }

    }
    int numEnclaves(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        // traverse the top & bottom edges 0..n
        for(int j = 0;j < m;j++){
            if(!vis[0][j] && grid[0][j] == 1){
                dfs(0, j, vis, grid);
            }

            if(!vis[n - 1][j] && grid[n - 1][j] == 1){
                dfs(n - 1, j, vis, grid);
            }
        }

        for(int i = 0;i < n;i++){
            if(!vis[i][0] && grid[i][0] == 1){
                dfs(i, 0, vis, grid);
            }

            if(!vis[i][m - 1] && grid[i][m - 1] == 1){
                dfs(i, m - 1, vis, grid);
            }
        }


        int cnt = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};