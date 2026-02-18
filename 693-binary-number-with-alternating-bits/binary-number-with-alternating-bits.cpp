class Solution {
public:
    bool hasAlternatingBits(int n) {
        while(n){
            int bit = n & 1;
            int alter = (n >> 1) & 1;

            if((n >> 1) && bit == alter)
                return false;

            n >>= 1;
        }

        return true;
    }
};