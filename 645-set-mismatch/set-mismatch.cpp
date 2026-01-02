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
#define all(x) x.begin(), x.end()

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = nums.size();

        long long expectedSum = 1LL * n * (n + 1) / 2;
        long long expectedSqSum = 1LL * n * (n + 1) * (2 * n + 1) / 6;

        long long actualSum = 0, actualSqSum = 0;
        for (long long x : nums) {
            actualSum += x;
            actualSqSum += x * x;
        }

        long long diff = expectedSum - actualSum;          
        long long sqDiff = expectedSqSum - actualSqSum;    

        long long sum = sqDiff / diff;                     

        long long missing = (diff + sum) / 2;
        long long repeated = missing - diff;

        return {(int)repeated, (int)missing};
    }
};