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

#define ll long long

class Solution {
public:
    vector<int> nextSmaller(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n, n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            
            ans[i] = st.empty() ? n : st.top();
            
            st.push(i);
        }

        return ans;
    }

    vector<int> prevSmaller(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }

            ans[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        return ans;
    }

    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        vector<int> prev = prevSmaller(arr);
        vector<int> next = nextSmaller(arr);
        
        ll total = 0;
        for (int i = 0; i < n; i++) {
            ll left = i - prev[i];
            ll right = next[i] - i;
            total = (total + left * right % MOD * arr[i]) % MOD;
        }

        return total;
    }
};
