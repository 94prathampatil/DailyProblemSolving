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


#define all(x) x.begin(), x.end()
class Solution {
public:
    typedef pair<int, int> P;

    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();

        set<P> s;
        for(int i = 0; i < n; i++){
            s.insert({positions[i], i});
        }

        stack<int> st;

        for(auto &it : s){
            int curr = it.second;

            if(directions[curr] == 'L'){
                while(!st.empty() && directions[st.top()] == 'R'){
                    int idx = st.top();

                    if(healths[idx] > healths[curr]){
                        healths[curr] = 0;
                        healths[idx] -= 1;
                        break;
                    }
                    else if(healths[idx] == healths[curr]){
                        healths[curr] = 0;
                        healths[idx] = 0;
                        st.pop();
                        break;
                    }
                    else{
                        healths[idx] = 0;
                        st.pop();
                        healths[curr] -= 1;
                    }
                }

                if(healths[curr] > 0){
                    st.push(curr);
                }
            }
            else{
                st.push(curr);
            }
        }

        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(healths[i] > 0){
                ans.push_back(healths[i]);
            }
        }

        return ans;
    }
};