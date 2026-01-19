class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> pref(n, vector<int>(m, 0));

        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int left = (j > 0) ? pref[i][j - 1] : 0;
                int top = (i > 0) ? pref[i - 1][j] : 0;
                int topLeft = (i > 0 && j > 0) ? pref[i - 1][j - 1] : 0;

                pref[i][j] = left + top - topLeft + mat[i][j];
            }
        }

        int ans = 0;
        int s = 1, e = min(n, m), mid = s + (e - s) / 2;

        // Try all square sizes
        
        while(s <= e){
            bool ok = false;
            for (int i = 0; i + mid - 1 < n; i++) {
                for (int j = 0; j + mid - 1 < m; j++) {

                    int i2 = i + mid - 1;
                    int j2 = j + mid - 1;

                    int sum = pref[i2][j2];
                    if (i > 0) sum -= pref[i - 1][j2];
                    if (j > 0) sum -= pref[i2][j - 1];
                    if (i > 0 && j > 0) sum += pref[i - 1][j - 1];

                    if (sum <= threshold) {
                        ok = true;
                        break;
                    }
                }
            }

            if(ok){
                ans = mid;
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }

            mid = s + (e - s) / 2;
        }
            
        

        return ans;
    }
};
