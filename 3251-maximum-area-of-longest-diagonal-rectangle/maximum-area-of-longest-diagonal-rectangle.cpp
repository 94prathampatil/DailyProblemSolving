class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dim) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = dim.size();
        int maxi = 0, maxD = 0;

        for(int i = 0;i < n;i++){
            int l = dim[i][0];
            int w = dim[i][1];

            int currDia = l * l + w * w;

            if(currDia > maxD || (currDia == maxD && l * w > maxi)){
                maxD = currDia;
                maxi = l * w;
            }
        }

        return maxi;
    }
};