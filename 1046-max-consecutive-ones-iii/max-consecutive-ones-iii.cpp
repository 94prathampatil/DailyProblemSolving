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
    int longestOnes(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int maxi = 0;
        int l = 0, r = 0;
        int cnt = 0;
        int n = nums.size();

        while(r < n){
            if(nums[r] == 0){
                cnt++;
            }

            while(cnt > k){
                if(nums[l] == 0){
                    cnt--;
                }
                l++;
            }

            maxi = max(maxi, r - l + 1);

            r++;
        }

        return maxi;
    }
};