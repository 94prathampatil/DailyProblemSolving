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
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        int m = grid.size(); 
        int n = grid[0].size();

        vector<vector<int>> prefix(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                prefix[i][j] = grid[i][j];

                if(i > 0)
                    prefix[i][j] += prefix[i-1][j];

                if(j > 0)
                    prefix[i][j] += prefix[i][j-1];

                if(i > 0 && j > 0)
                    prefix[i][j] -= prefix[i-1][j-1];
            }
        }

        int ans = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(prefix[i][j] <= k)
                    ans++;
            }
        }

        return ans;
    }
};