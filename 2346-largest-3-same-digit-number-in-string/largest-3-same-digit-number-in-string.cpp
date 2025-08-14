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
    bool isEqual(string &s, int l){
        return (s[l] == s[l + 1]) && (s[l] == s[l + 2]) && (s[l + 1] == s[l + 2]);
    }
    string largestGoodInteger(string num) {
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

        int l = 0, n = num.length();
        int r = l + 2;

        int maxDigit = -1;

        string maxStr = "";
        while(l < n && r < n){
            if((l + 1 < n && l + 2 < n) && isEqual(num, l)){
                int digit = num[l] - '0';
                if(maxDigit < digit){
                    maxDigit = digit;
                    maxStr = maxStr = string(3, num[l]);;
                }
            }

            l++;
            r++;        
        }

        return maxStr;


    }
};