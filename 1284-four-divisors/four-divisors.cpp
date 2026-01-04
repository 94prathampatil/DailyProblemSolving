class Solution {
public:
    int solve(int n){
        vector<int> ans;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                ans.push_back(i);

                if (i != n / i) {
                    ans.push_back(n / i);
                }
            }
        }

        if(ans.size() == 4)
            return accumulate(ans.begin(), ans.end(), 0);
    
        
        return 0;
    }
    int sumFourDivisors(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int ans = 0;

        for(auto &n : nums){
            ans += solve(n);
        }


        return ans;
    }
};