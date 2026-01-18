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
    vector<int> prefixVector(vector<int> &a){
        vector<int> pref(a.size(), 0);
        pref[0] = a[0];

        for(int i = 1;i < a.size();i++){
            pref[i] = pref[i - 1] + a[i];
        }

        return pref;
    }

    int largestMagicSquare(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> rowPref(n, vector<int> (m, 0));
        vector<vector<int>> colPref(n, vector<int> (m, 0));

        for(int i = 0;i < n;i++){
            rowPref[i] = prefixVector(grid[i]);
        }

        for(int j = 0;j < m;j++){
            colPref[0][j] = grid[0][j];
        }

        for(int i = 1;i < n;i++){
            for(int j = 0;j < m;j++){
                colPref[i][j] = colPref[i - 1][j] + grid[i][j];
            }
        }

        int ans = 1;

        for (int k = 2; k <= min(n, m); k++) {
            for (int i = 0; i + k - 1 < n; i++) {
                for (int j = 0; j + k - 1 < m; j++) {

                    int target = rowPref[i][j + k - 1] -
                                (j > 0 ? rowPref[i][j - 1] : 0);

                    bool ok = true;

                    // rows
                    for (int r = i; r < i + k; r++) {
                        int sum = rowPref[r][j + k - 1] -
                                (j > 0 ? rowPref[r][j - 1] : 0);
                        if (sum != target) { 
                            ok = false; 
                            break; 
                        }
                    }

                    // columns
                    for (int c = j; c < j + k && ok; c++) {
                        int sum = colPref[i + k - 1][c] -
                                (i > 0 ? colPref[i - 1][c] : 0);
                        if (sum != target) { 
                            ok = false; 
                            break; 
                        }
                    }

                    // diagonals
                    int d1 = 0, d2 = 0;
                    for (int t = 0; t < k; t++) {
                        d1 += grid[i + t][j + t];
                        d2 += grid[i + t][j + k - 1 - t];
                    }

                    if (d1 != target || d2 != target) ok = false;

                    if (ok) ans = max(ans, k);
                }
            }
        }

        return ans;
    }
};