class Solution {
public:
    string addBinary(string a, string b) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int l1 = a.length(), l2 = b.length();
        int carry = 0;
        string ans = "";
        int i = l1 - 1, j = l2 - 1;

        while(i >= 0 || j >= 0 || carry != 0){
            int one = (i >= 0 && a[i] == '1') ? 1 : 0;
            int two = (j >= 0 && b[j] == '1') ? 1 : 0;

            int s = one + two + carry;

            carry = s / 2;
            s %= 2;

            ans += (s + '0');

            i--, j--;
        }

        reverse(ans.begin(), ans.end());

        return ans;

    }
};