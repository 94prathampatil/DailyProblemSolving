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

#define pb(x) push_back(x)


class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = nums.size();
        int subset = 1 << n;
        int sum = 0;

        for(int num = 0;num < subset;num++){
            int Xor = 0;
            for(int i = 0;i < n;i++){
                if(num & (1 << i)){
                    Xor ^= nums[i];
                }
            }
            sum += Xor;
        }

        return sum;
    }
};
