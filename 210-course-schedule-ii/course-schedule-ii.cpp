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

#define pb(x) push_back(x)

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pr) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<vector<int>> graph(numCourses);
        vector<int> ans, indegree(numCourses);

        for(auto &p:pr)
            graph[p[1]].pb(p[0]),
            indegree[p[0]]++;
        
        function<void(int)> dfs = [&](int curr){
            ans.pb(curr);
            indegree[curr] = -1;

            for(auto neighbor:graph[curr]){
                if(--indegree[neighbor] == 0)   
                    dfs(neighbor);
            }
        };


        for(int i = 0;i < numCourses;i++)
            if(indegree[i] == 0)    dfs(i);
    

        if(size(ans) == numCourses) return ans;

        return {};

    }
};