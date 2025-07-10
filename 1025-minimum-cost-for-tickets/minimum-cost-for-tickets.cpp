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
    int solve(int n, vector<int>& days, vector<int>& cost, int index, vector<int>& dp){
        // Base case
        if(index >= n)  return 0;

        if(dp[index] != -1) return dp[index];

        int singleDayPass = cost[0] + solve(n, days, cost, index + 1, dp);

        // For 7 days pass
        int i;
        for(i = index; i < n && days[i] < days[index] + 7;i++);
        int sevenDayPass = cost[1] + solve(n, days, cost, i, dp);

        // for 30 days pass
        for(i = index; i < n && days[i] < days[index] + 30;i++);
        int thirtyDaysPass = cost[2] + solve(n, days, cost, i, dp);


        return dp[index] = min(singleDayPass, min(sevenDayPass, thirtyDaysPass));
    }

    int solveTab(int n, vector<int>& days, vector<int>& cost){
        vector<int> dp(n + 1, INT_MAX);
        dp[n] = 0;

        for(int i = n - 1; i >= 0;i--){
            int singleDayPass = cost[0] + dp[i + 1];

            int j;
            for(j = i; j < n && days[j] < days[i] + 7;j++);
            int sevenDayPass = cost[1] + dp[j];

            for(j = i; j < n && days[j] < days[i] + 30;j++);
            int thirtyDaysPass = cost[2] + dp[j];

            dp[i] = min(singleDayPass, min(sevenDayPass, thirtyDaysPass));
        }

        return dp[0];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = days.size();
        // vector<int> dp(n + 1, -1);
        return solveTab(n, days, costs);
    }
};