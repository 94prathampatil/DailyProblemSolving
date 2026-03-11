class Solution {
public:
    int bitwiseComplement(int n) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        if(n == 0) return 1;

        int count = 0;
        int res = 0;

        while(n){
            int r = n % 2;
            res += pow(2, count) * !r;
            count++;

            n /= 2;
        }

        return res;
    }
};