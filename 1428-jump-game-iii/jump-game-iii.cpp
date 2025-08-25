class Solution {
public:
    bool solve(int i, vector<int>& arr){
        if(i >= arr.size() || i < 0)    return false;
        if(arr[i] == 0) return true;
        if(arr[i] < 0)  return false;

        arr[i] = -arr[i];
        // plus
        bool plus = solve(i + arr[i], arr);
        // minus
        bool minus = solve(i - arr[i], arr);

        return plus || minus;
    }

    bool canReach(vector<int>& arr, int start) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        return solve(start, arr);
    }
};