class Solution {
public:
    int gcd(int a, int b){
        if(b == 0) return a;

        return gcd(b, a % b);
    }

    int gcdOfOddEvenSums(int n) {
        ios_base::sync_with_stdio(0);
        cout.tie(0);
        cin.tie(0);

        int oddSum = n * n, evenSum = n * (n + 1);

        return gcd(max(oddSum, evenSum), min(oddSum, evenSum));

    }
};