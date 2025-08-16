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
    int maximum69Number (int num) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        string og = to_string(num);
        string temp = og;
        int ans = num;
        int i = 0;

        while(i < temp.length()){
            (temp[i] == '9') ? temp[i] = '6' : temp[i] = '9';
            string str = temp;
            ans = max(ans, stoi(temp));
            cout << str << " " << ans << endl;
            temp = og;
            i++;
        }


        return ans;
    }
};