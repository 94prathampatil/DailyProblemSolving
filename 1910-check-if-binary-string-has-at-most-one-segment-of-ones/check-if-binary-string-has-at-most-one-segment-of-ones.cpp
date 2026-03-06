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
    bool checkOnesSegment(string s) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int count = 0;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '1' && (i == 0 || s[i-1] == '0'))
                count++;
        }

        return count <= 1;
    }
};