class Solution {
public:
    typedef long long ll;
    int n;

    ll solve(int i, int trend, vector<int> &nums, vector<vector<ll>> &dp){
        if(i == n)  {
            if(trend == 3){
                return 0;
            }
            else{
                return LLONG_MIN / 2;
            }
        }

        if(dp[i][trend] != LLONG_MIN)  
            return dp[i][trend];
            

        ll take = LLONG_MIN / 2;
        ll skip = LLONG_MIN / 2;

        if(trend == 0){
            skip = solve(i + 1, 0, nums, dp);
        }

        if(trend == 3){
            take = nums[i];
        }

        if(i + 1 < n){
            ll curr = nums[i];
            ll next = nums[i + 1];

            if(trend == 0 && next > curr){
                take = max(take, curr + solve(i + 1, 1, nums, dp));
            }
            else if(trend == 1){
                if(next > curr){
                    take = max(take, curr + solve(i + 1, 1, nums, dp));
                }
                else if(next < curr){
                    take = max(take, curr + solve(i + 1, 2, nums, dp));
                }
            }
            else if(trend == 2){
                if(next < curr){
                    take = max(take, curr + solve(i + 1, 2, nums, dp));
                }
                else if(next > curr){
                    take = max(take, curr + solve(i + 1, 3, nums, dp));
                }
            }
            else if(trend == 3){
                if(next > curr){
                    take = max(take, curr + solve(i + 1, 3, nums, dp));
                }
            }
        }


        return dp[i][trend] = max(take, skip);

    }

    ll maxSumTrionic(vector<int>& nums) {
        n = nums.size();

        vector<vector<ll>> dp(n + 1, vector<ll> (4, LLONG_MIN));

        return solve(0, 0, nums, dp);
    }
};