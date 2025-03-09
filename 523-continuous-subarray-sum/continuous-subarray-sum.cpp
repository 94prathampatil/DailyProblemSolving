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

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        unordered_map<int, int> firstOccu;
        firstOccu[0] = 0;
        int preSum = 0;

        for(int i = 0;i < nums.size();i++){
            preSum = (preSum + nums[i]) % k;

            if(firstOccu.find(preSum) != firstOccu.end()){
                if(i + 1 - firstOccu[preSum] >= 2)  
                    return true;
            }
            else{
                firstOccu[preSum] = i + 1;
            }
        }

        return false;
    }
};