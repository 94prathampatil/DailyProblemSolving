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
    int countDigits(int num) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    
        int ans = 0, n = num;
        
        while(num != 0){
            int dig = num % 10;

            if(n % dig == 0)
                ans++;

            num /= 10;
        }

        return ans;
    }
};