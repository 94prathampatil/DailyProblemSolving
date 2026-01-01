#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<int> ans;
        int carry = 1; // because we are adding +1

        for (int i = digits.size() - 1; i >= 0; i--) {
            int digit = digits[i] + carry;
            carry = digit / 10;
            digit = digit % 10;
            ans.push_back(digit);
        }

        if (carry)
            ans.push_back(carry);

        reverse(ans.begin(), ans.end());
        return ans;
    }
};