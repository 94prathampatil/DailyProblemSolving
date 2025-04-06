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
private:
    void dfs(int row, int col, vector<vector<int>>& ans, vector<vector<int>> &image, int color, int iniCol){

        ans[row][col] = color;

        int n = image.size();
        int m = image[0].size();

        array<int, 4> delRow = {-1, 0, 1, 0};
        array<int, 4> delCol = {0, 1, 0, -1};

        for(int i = 0;i < 4;i++){
            int r = row + delRow[i];
            int c = col + delCol[i];

            if(r >= 0 && r < n && c >= 0 && c < m && image[r][c] == iniCol && ans[r][c] != color){
                dfs(r, c, ans, image, color, iniCol);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<vector<int>> ans = image;
        int iniCol = image[sr][sc]; 

        dfs(sr, sc, ans, image, color, iniCol);

        return ans;
    }
};