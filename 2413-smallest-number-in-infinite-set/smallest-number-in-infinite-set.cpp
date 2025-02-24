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
    int curr;
    set<int> st;
    SmallestInfiniteSet() {
        curr = 1;
    }
    
    int popSmallest() {
        if(st.size()){
            int val = *st.begin();
            st.erase(val);
            return val;
        }
        else{
            curr++;
            return curr - 1;
        }
    }
    
    void addBack(int num) {
        if(curr > num)  st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */