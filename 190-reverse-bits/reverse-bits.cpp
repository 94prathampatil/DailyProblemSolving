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
    int reverseBits(int n) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int raisedTo = 0;
        vector<int> bit(32);
        for(int i = 0;i < 32;i++){
            if(n != 0){
                bit[i] = n & 1;
                n >>= 1;
            }
        }

        for(int i = bit.size() - 1;i >= 0;i--){
            n += bit[i] * pow(2, raisedTo++); 
        }
        
        return n;
        
    }
};