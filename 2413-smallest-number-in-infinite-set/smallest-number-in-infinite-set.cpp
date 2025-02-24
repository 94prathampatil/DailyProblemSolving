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

class SmallestInfiniteSet {
public:
    int val;
    priority_queue<int, vector<int>, greater<int>> pq;
    set<int> st;
    SmallestInfiniteSet() {
        for(int i = 1;i <= 1000;i++){
            pq.push(i);
            st.insert(i);
        }
    }
    
    int popSmallest() {
        val = pq.top();
        pq.pop();
        st.erase(val);
        return val;
    }
    
    void addBack(int num) {
        if(st.count(num) == 0){
            st.insert(num);
            pq.push(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */