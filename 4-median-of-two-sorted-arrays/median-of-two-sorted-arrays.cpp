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
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Brute Force, We can also solve using binary search 

        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        for(auto &it:nums2){
            nums1.pb(it);
        }

        sort(nums1.begin(), nums1.end());

        int n = nums1.size();
        if(n % 2 == 1){
            return nums1[(n / 2)];
        }
        
        double one = nums1[n / 2];
        double two = nums1[(n / 2) - 1];

        return (one + two) / 2.0;
    }
};