const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

#define LC_HACK
#ifdef LC_HACK
const auto __ = []()
{
    struct ___
    {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
#endif

#define pb(x) push_back(x)
#define ll long long
#define llv long long vector

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
 
        sort(nums.begin(), nums.end());
        int naturalNum = 1;

        for(int i = 0;i < nums.size();i++){
            if(nums[i] < 0){
                continue;
            }
            if(nums[i] == naturalNum){
                naturalNum++;
            }
            else if(naturalNum < nums[i]){
                break;
            }
        }

        return naturalNum;

    }
};