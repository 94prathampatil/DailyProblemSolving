class Solution {
public:
    int bitwiseComplement(int n) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int mask = 1;

        while(mask < n){
            mask = (mask << 1) | 1;
        }

        return n ^ mask;
    }
};