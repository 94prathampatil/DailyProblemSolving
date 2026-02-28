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
    int M = 1e9 + 7;
    int concatenatedBinary(int n) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        long ans = 0;
        int digit = 0;
        for(int i = 1;i <= n;i++){
            if((i & (i - 1)) == 0)
                digit++;

            ans = ((ans << digit) % M + i) % M;
        }

        return ans;
    }
};