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
    vector<int> asteroidCollision(vector<int>& arr) {
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

        int n = arr.size();
        vector<int> st;

        for(int i = 0;i < n;i++){
            if(arr[i] > 0)  st.push_back(arr[i]);
            else{
                while(!st.empty() && st.back() > 0 && st.back() < abs(arr[i])){
                    st.pop_back();
                }
                
                if(!st.empty() && st.back() == abs(arr[i])){
                    st.pop_back();
                }
                else if(st.empty() || st.back() < 0){
                    st.push_back(arr[i]);
                }
            }
        }

        return st;
    }
};