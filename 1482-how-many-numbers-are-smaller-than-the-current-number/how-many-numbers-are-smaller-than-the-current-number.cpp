#define all(x) x.begin(), x.end()
#define pb(x) push_back(x)

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = nums.size();
        vector<int> ans(n, 0);

        for(int i = 0;i < n;i++){
            int cnt = 0;
            for(int j = 0;j < n;j++){
                if(j != i && nums[j] < nums[i]){
                    cnt++;
                }
            }
            ans[i] = cnt;
        }

        return ans;
    }
};