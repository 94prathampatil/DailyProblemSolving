#define all(x) x.begin(), x.end()

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        sort(all(arr));

        int minDiff = INT_MAX;

        for(int i = 0;i < arr.size() - 1;i++){
            minDiff = min(abs(arr[i] - arr[i + 1]), minDiff);
        }

        vector<vector<int>> ans;

        for(int i = 0;i < arr.size() - 1;i++){
            if(abs(arr[i] - arr[i + 1]) == minDiff)
                ans.push_back({arr[i], arr[i + 1]});
        }
        

        return ans;
    }
};