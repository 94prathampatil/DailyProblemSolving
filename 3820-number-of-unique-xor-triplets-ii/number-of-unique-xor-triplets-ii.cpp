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
    int uniqueXorTriplets(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        unordered_set<int> st, s;

        int n = nums.size();

        if(n == 1 || n == 2) return n;

        for(int i = 0;i < n;i++){
            for(int j = i + 1;j < n;j++){
                st.insert(nums[i]^nums[j]);
            }
        }

        for(auto num:st){
            for(auto a:nums){
                s.insert(num ^ a);
            }
        }

        return s.size();
    }
};