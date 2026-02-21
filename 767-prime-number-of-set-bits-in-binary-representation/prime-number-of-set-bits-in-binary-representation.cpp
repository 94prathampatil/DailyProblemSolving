class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        unordered_set<int> seive = {2, 3, 5, 7, 11, 13, 17, 19};
        int cnt = 0;

        for(int i = left;i <= right;i++){
            if(seive.count(__builtin_popcount(i)))
                cnt++;
        }

        return cnt;
    }
};