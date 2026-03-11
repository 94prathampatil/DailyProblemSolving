class Solution {
public:
    int findComplement(int num) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int mask = 1;

        while(mask < num){
            mask = (mask << 1) | 1;
        }

        return num ^ mask;
    }
};