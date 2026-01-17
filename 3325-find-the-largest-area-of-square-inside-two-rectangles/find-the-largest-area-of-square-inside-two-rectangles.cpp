class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = bottomLeft.size();
        long long maxi = 0;
        for(int i = 0;i < n;i++){
            for(int j = i + 1;j < n;j++){                
                int x2 = min(topRight[i][0], topRight[j][0]);
                int x3 = max(bottomLeft[i][0], bottomLeft[j][0]);

                int width = x2 - x3;

                int y2 = min(topRight[i][1], topRight[j][1]);
                int y3 = max(bottomLeft[i][1], bottomLeft[j][1]);

                int height = y2 - y3;

                long long side = min(width, height);
                maxi = max(maxi, side);
            }
        }

        return maxi * maxi;
    }
};