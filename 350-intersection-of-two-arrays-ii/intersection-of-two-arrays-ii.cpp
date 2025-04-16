class Solution {
public:
    vector<int> intersect(vector<int>& a, vector<int>& b) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    
    unordered_map<int, int> ctr;
    for (int i : a)
        ctr[i]++;
    vector<int> out;
    for (int i : b)
        if (ctr[i]-- > 0)
            out.push_back(i);
    return out;
}
};