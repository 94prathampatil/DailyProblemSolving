class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();

        vector<long long> done(n + 1, 0);

        for(int i = 0;i <  m;i++){
            for(int j = 0;j < n;++j){
                done[j + 1] = max(done[j + 1], done[j]) + 1LL * mana[i] * skill[j];
            }

            for(int j = n - 1;j > 0;--j){
                done[j] = done[j + 1] - 1LL * mana[i] * skill[j];
            }
        }

        return done[n];
    }
};