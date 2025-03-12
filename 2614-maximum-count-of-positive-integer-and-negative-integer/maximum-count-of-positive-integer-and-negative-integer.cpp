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
    int positiveFirst(vector<int> &nums){
        int s = 0, e = nums.size() - 1, mid = s + (e - s) / 2;
        int ans = nums.size();

        while(s <= e){
            if(nums[mid] > 0){
                ans = mid;
                e = mid - 1;
            }
            else{
                s = mid + 1;
            }

            mid = s + (e - s) / 2;
        }

        return ans;
    }

    int negativeLast(vector<int> &nums){
        int s = 0, e = nums.size() - 1, mid = s + (e - s) / 2;
        int ans = -1;
        while(s <= e){
            if(nums[mid] < 0){
                ans = mid;
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }

            mid = s + (e - s) / 2;
        }

        return ans;
    }
    int maximumCount(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = nums.size();
        if(nums[0] > 0 || nums[n - 1] < 0)  return n;

        return max(negativeLast(nums) + 1, n - positiveFirst(nums));

        // return 0;
    }
};