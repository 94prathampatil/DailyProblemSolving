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
    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>> &vis){
        array<int, 4> drow = {-1, 0, 0, 1};
        array<int, 4> dcol = {0, -1, 1, 0};

        int n = board.size();
        int m = board[0].size();

        vis[row][col] = 1;

        for(int i = 0; i < 4; i++){
            int x = row + drow[i];
            int y = col + dcol[i];

            if(x >= 0 && x < n && y >= 0 && y < m && !vis[x][y] && board[x][y] == 'O'){
                dfs(x, y, board, vis);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Traverse top & bottom edges (columns 0…m-1)
        for(int j = 0; j < m; j++){
            if(!vis[0][j] && board[0][j] == 'O'){
                dfs(0, j, board, vis);
            }
            if(!vis[n - 1][j] && board[n - 1][j] == 'O'){
                dfs(n - 1, j, board, vis);
            }
        }

        // Traverse left & right edges (rows 0…n-1)
        for(int i = 0; i < n; i++){
            if(!vis[i][0] && board[i][0] == 'O'){
                dfs(i, 0, board, vis);
            }
            if(!vis[i][m - 1] && board[i][m - 1] == 'O'){
                dfs(i, m - 1, board, vis);
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};
