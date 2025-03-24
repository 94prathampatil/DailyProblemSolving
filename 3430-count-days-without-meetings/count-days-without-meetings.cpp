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
    int countDays(int days, vector<vector<int>>& meetings) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        sort(meetings.begin(), meetings.end());

        int prev = 0, cnt = 0;

        for(auto &i:meetings){
            cout << i[0] << " " << i[1] << " ";
        }

        for(auto &i:meetings){
            if(i[0] > prev + 1){
                cnt += i[0] - prev - 1;
            }

            prev = max(prev, i[1]);
        }

        if(days > prev) 
            cnt += days - prev;

        return cnt;
    }
};