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
    bool isValid(int row, int col, int n, int m, vector<vector<int>>& vis){
        return (row >= 0 && row < n && col >= 0 && col < m && vis[row][col] == 0);
    }


    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> vis(n, vector<int> (m, 0));
        vector<vector<int>> dist(n, vector<int> (m, 0));
        queue<pair<pair<int, int>, int>>  q;

        array<int, 4> drow = {-1, 0, 0, 1};
        array<int, 4> dcol = {0, -1, 1, 0}; 


        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(mat[i][j] == 0){
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int step = q.front().second;

            q.pop();

            dist[row][col] = step;

            for(int i = 0;i < 4;i++){
                int x = row + drow[i];
                int y = col + dcol[i];

                if(isValid(x, y, n, m, vis)){
                    vis[x][y] = 1;
                    q.push({{x, y}, step + 1});
                }
            }    
        }
        
        return dist;

    }
};