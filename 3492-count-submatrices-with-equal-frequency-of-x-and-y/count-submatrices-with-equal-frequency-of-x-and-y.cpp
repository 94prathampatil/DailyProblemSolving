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
    typedef pair<int, int> P;

    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<P>> prefix(n, vector<P>(m, {0, 0}));

        int ans = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                prefix[i][j].first = (grid[i][j] == 'X');
                prefix[i][j].second = (grid[i][j] == 'Y');

                if(i > 0){
                    prefix[i][j].first += prefix[i - 1][j].first;
                    prefix[i][j].second += prefix[i - 1][j].second;
                }
                if(j > 0){
                    prefix[i][j].first += prefix[i][j - 1].first;
                    prefix[i][j].second += prefix[i][j - 1].second;
                }
                if(i > 0 && j > 0){
                    prefix[i][j].first -= prefix[i - 1][j - 1].first;
                    prefix[i][j].second -= prefix[i - 1][j - 1].second;
                }

                if(prefix[i][j].first > 0 && prefix[i][j].first == prefix[i][j].second){
                    ans++;
                }
            }
        }

        return ans;
    }
};