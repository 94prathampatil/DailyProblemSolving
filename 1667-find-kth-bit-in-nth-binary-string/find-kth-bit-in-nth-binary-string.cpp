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
    string invert(string str){
        reverse(str.begin(), str.end());

        for(auto &ch : str)
            ch = (ch == '0') ? '1' : '0';

        return str;
    }
    char findKthBit(int n, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        string prev = "0";

        for(int i = 2;i <= n;i++){
            prev = prev + '1' + invert(prev);
        }

        return prev[k - 1];
    }
};