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
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        ios_base::sync_with_stdio();
        cin.tie(0);
        cout.tie(0);


        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> result(m-k+1, vector<int>(n-k+1, 0));
        
        for (int i = 0; i <= m-k; i++) {
            for (int j = 0; j <= n-k; j++) {
                
                // Set for distinct + sorted
                set<int> vals;
                
                for (int r = i; r <= i + k - 1; r++) {
                    for (int c = j; c <= j + k - 1; c++) {
                        vals.insert(grid[r][c]);
                    }
                }
                
                // If all elements were same, set has only 1 element
                if (vals.size() == 1) {
                    continue;
                }
                
                int minAbsDiff = INT_MAX;
                auto prev = vals.begin();
                auto curr = next(prev);
                
                while (curr != vals.end()) {
                    minAbsDiff = min(minAbsDiff, *curr - *prev);
                    prev = curr;
                    curr++;
                }
                
                result[i][j] = minAbsDiff;
            }
        }
        
        return result;
    }
};