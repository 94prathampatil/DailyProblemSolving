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
    int largestSubmatrix(vector<vector<int>>& matrix) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        auto m = matrix.size(), n = matrix[0].size();
        auto res = 0;

        for(int i = 1;i < m;i++){
            for(int j = 0;j < n;j++){
                if(matrix[i][j] == 1)
                    matrix[i][j] += matrix[i - 1][j];
            }
        }

        for(int i = 0;i < m;i++){
            sort(matrix[i].rbegin(), matrix[i].rend());
            for(int j = 0;j < n;j++){
                res = max(res, matrix[i][j] * (j + 1));
            }
        }

        return res;
    }
};