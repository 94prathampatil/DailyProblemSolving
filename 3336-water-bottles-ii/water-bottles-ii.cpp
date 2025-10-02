class Solution {
public:
    int maxBottlesDrunk(int n, int b) {
        int ans = n;
        while(n >= b){
            n -= b - 1, b++, ans++;
        }

        return ans;
    }
};