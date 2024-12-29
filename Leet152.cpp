class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int ans = INT_MIN, pre = 1, suff = 1, n = nums.size();

        for (int i = 0; i < nums.size(); i++)
        {
            if (pre == 0)
                pre = 1;
            if (suff == 0)
                suff = 1;

            pre *= nums[i];
            suff *= nums[n - i - 1];

            ans = max(ans, max(pre, suff));
        }

        return ans;
    }
};