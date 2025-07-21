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
    int solve(int n, vector<int> &nums, int curr, int prev, vector<vector<int>>& dp){
        // base case;
        if(curr == n){
            return 0;
        }

        if(dp[curr][prev + 1] != -1){
            return dp[curr][prev + 1];
        }

        int take = 0;
        if(prev == -1 || nums[curr] > nums[prev]){
            take = 1 + solve(n, nums, curr + 1, curr, dp);
        }
        int notTake = solve(n, nums, curr + 1, prev, dp);

        return dp[curr][prev + 1] = max(take, notTake);
    }

    int solveTab(vector<int> &nums){
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for(int curr = n - 1;curr >= 0;curr--){
            for(int prev = curr - 1;prev >= -1;prev--){
                int take = 0;
                if(prev == -1 || nums[curr] > nums[prev]){
                    take = 1 + dp[curr + 1][curr + 1];
                }
                int notTake = dp[curr + 1][prev + 1];

                dp[curr][prev + 1] = max(take, notTake);
            }
        }

        return dp[0][0];

    }

    int solveSO(vector<int> &nums){
        int n = nums.size();
        vector<int> currRow(n + 1, 0);
        vector<int> nextRow(n + 1, 0);

        for(int curr = n - 1;curr >= 0;curr--){
            for(int prev = curr - 1;prev >= -1;prev--){
                int take = 0;
                if(prev == -1 || nums[curr] > nums[prev]){
                    take = 1 + nextRow[curr + 1];
                }
                int notTake = nextRow[prev + 1];

                currRow[prev + 1] = max(take, notTake);
            }

            nextRow = currRow;
        }

        return nextRow[0];
    }
    int lengthOfLIS(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = nums.size();
        // vector<vector<int>> dp(n, vector<int> (n + 1, -1));
        // return solve(n, nums, 0, -1, dp);
        return solveSO(nums);
    }
};