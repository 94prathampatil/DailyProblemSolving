// A two pointer approach question of subarray that state to find the length of non-repeating character
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        unordered_map<char, int> mp;
        int i = 0, j = 0, maxLen = 0;

        while (j < s.length())
        {
            if (mp.find(s[j]) != mp.end())
            {
                if (mp[s[j]] >= i)
                {
                    i = mp[s[j]] + 1;
                }
            }
            maxLen = max(maxLen, j - i + 1);
            mp[s[j]] = j;
            j++;
        }

        return maxLen;
    }
};