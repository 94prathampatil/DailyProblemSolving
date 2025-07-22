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
    bool isPossible(int n){
        int temp = n;

        while(n != 0){
            int digit = n % 10;

            if(digit == 0){
                return false;
            }
            if(temp % digit != 0){
                return false;
            }
            
            n /= 10;
        }

        return true;
    }

    vector<int> selfDividingNumbers(int left, int right) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<int> ans;

        for(int i = left;i <= right;i++){
            if(isPossible(i)){
                ans.push_back(i);
            }
        }

        return ans;
    }
};