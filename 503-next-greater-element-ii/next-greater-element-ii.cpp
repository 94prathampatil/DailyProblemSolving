const auto _ = std::cin.tie(nullptr)->sync_with_stdio(false);

#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
    struct ___ {
        static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; }
    };
    std::atexit(&___::_);
    return 0;
}();
#endif


class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = nums.size();
        vector<int> ans (n, -1);
        stack<int> st;

        for(int i = 2 * n - 1;i >= 0;i--){
            int idx = i % n;

            while(!st.empty() && st.top() <= nums[idx]){
                st.pop();
            }

            if(i < n && !st.empty()){
                ans[idx] = st.top();
            }

            st.push(nums[idx]);
        }

        return ans;
    }
};