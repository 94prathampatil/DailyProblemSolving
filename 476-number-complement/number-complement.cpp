#include<bits/stdc++.h>

class Solution {
public:
    int findComplement(int num) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        int bit = floor(log2(num) + 1);
        int mask = pow(2, bit) - 1;

        return num ^ mask;

    }
};