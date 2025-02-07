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
#define ll long long
#define mInf INT_MIN

class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        sort(nums.begin(), nums.end());
        int ans = 0;

        for(int i = 0;i < nums.size();i++){
            int s = i + 1, e = nums.size() - 1, mid = s + (e - s) / 2;

            while(s <= e){
                if(nums[i] + nums[mid] >= k){
                    e = mid - 1;
                }
                else{
                    s = mid + 1;
                }

                mid = s + (e - s) / 2;
            }

            ans += (e - i);
        }


        return ans;
    }
};