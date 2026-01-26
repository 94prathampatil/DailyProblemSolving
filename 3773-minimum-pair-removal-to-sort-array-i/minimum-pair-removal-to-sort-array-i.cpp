typedef long long ll;
#define all(x) x.begin(), x.end()

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        int n = nums.size();

        vector<ll> temp(all(nums));

        set<pair<ll, int>> minPairSet;

        vector<int> nextIndex(n), prevIndex(n);

        for(int i = 0; i < n; i++){
            nextIndex[i] = i + 1;
            prevIndex[i] = i - 1;
        }

        int badPairs = 0;
        for(int i = 0; i < n - 1; i++){
            if(temp[i] > temp[i + 1])
                badPairs++;

            minPairSet.insert({temp[i] + temp[i + 1], i});
        }

        int oper = 0;

        while(badPairs){
            auto it = minPairSet.begin();
            int first = it->second;
            int second = nextIndex[first];

            minPairSet.erase(it);

            if(second >= n) continue;  // safety check

            int first_left = prevIndex[first];
            int second_right = nextIndex[second];

            // Remove old bad pair (first, second)
            if(temp[first] > temp[second])
                badPairs--;

            // Check (first_left, first)
            if(first_left >= 0){
                bool oldBad = temp[first_left] > temp[first];
                bool newBad = temp[first_left] > temp[first] + temp[second];

                if(oldBad && !newBad) badPairs--;
                if(!oldBad && newBad) badPairs++;

                minPairSet.erase({temp[first_left] + temp[first], first_left});
                minPairSet.insert({temp[first_left] + temp[first] + temp[second], first_left});
            }

            // Check (second, second_right)
            if(second_right < n){
                bool oldBad = temp[second] > temp[second_right];
                bool newBad = temp[first] + temp[second] > temp[second_right];

                if(oldBad && !newBad) badPairs--;
                if(!oldBad && newBad) badPairs++;

                minPairSet.erase({temp[second] + temp[second_right], second});
                minPairSet.insert({temp[first] + temp[second] + temp[second_right], first});

                prevIndex[second_right] = first;
            }

            nextIndex[first] = second_right;

            temp[first] += temp[second];

            oper++;
        }

        return oper;
    }
};
