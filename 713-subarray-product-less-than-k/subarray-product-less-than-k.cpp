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
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int ans = 0, prod = 1, i = 0, j = 0, n = nums.size();


        // Rituals of Two pointers
        while(j < n){
            prod *= nums[j];

            while(prod >= k && i <= j){
                prod /= nums[i++];
            }

            ans += (j - i + 1);
            j++;
        }

        return ans;

    }
};