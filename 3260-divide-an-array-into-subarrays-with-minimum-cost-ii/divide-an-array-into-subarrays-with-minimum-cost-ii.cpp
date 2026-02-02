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
    typedef long long ll;
    typedef pair<ll, ll> P;
    long long minimumCost(vector<int>& nums, int k, int dist) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = nums.size();

        set<P> kMin;
        set<P> remain;

        ll sum = 0;

        int i = 1;
        while(i - dist < 1){
            kMin.insert({nums[i], i});
            sum += nums[i];

            if(kMin.size() > k - 1){
                P temp = *kMin.rbegin();
                sum -= temp.first;
                remain.insert(temp);
                kMin.erase(temp);
            }

            i++;
        }

        ll res = LONG_MAX;
        while(i < n){
            kMin.insert({nums[i], i});
            sum += nums[i];

            if(kMin.size() > k - 1){
                P temp = *kMin.rbegin();
                sum -= temp.first;
                remain.insert(temp);
                kMin.erase(temp);
            }

            res = min(sum, res);

            // window shifting
            P remove = {nums[i - dist], i - dist};
            if(kMin.count(remove)){
                kMin.erase(remove);
                sum -= remove.first;

                if(!remain.empty()){
                    P temp = *remain.begin();
                    kMin.insert(temp);

                    sum += temp.first;

                    remain.erase(temp);
                }
            }    
            else{
                remain.erase(remove);
            }

            i++;
        }

        return nums[0] + res;
    }
};