class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<int> diffArr(1001, 0);

        for(auto &trip : trips){
            int passenger = trip[0];
            int s = trip[1];
            int e = trip[2];

            diffArr[s] += passenger;
            diffArr[e] -= passenger; 
        }

        int cnt = 0;
        for(int i = 0;i < 1001;i++){
            cnt += diffArr[i];

            if(cnt > capacity)
                return false;
        }

        return true;
    }
};