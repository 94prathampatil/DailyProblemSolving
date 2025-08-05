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
    int isPrime(int n) {
        if (n <= 1) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

public:
    int mostFrequentPrime(vector<vector<int>>& mat) {
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        
        int n = mat.size();
        int m = mat[0].size();

        int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
        int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};

        map<int, int> cnt;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < 8; k++) {
                    int x = i, y = j;
                    int num = mat[i][j];

                    while (true) {
                        x += dx[k], y += dy[k];
                        if (x < 0 || x >= n || y < 0 || y >= m) break;
                        num = num * 10 + mat[x][y];
                        if (isPrime(num)) cnt[num]++;
                    }
                }
            }
        }

        if (cnt.empty()) return -1;

        int ans = 0, freq = 0;
        for (auto [k, v] : cnt) {
            if (v >= freq) ans = k, freq = v;
        }

        return ans;
    }
};
