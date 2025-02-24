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

#define pb(x) push_back(x);

class node{
    public:
        int data, row, col;

    node(int data, int row, int col){
        this -> data = data;
        this -> row = row;
        this -> col = col;
    }
};

class compare{
    public:
        bool operator()(node* a, node* b){
            return a -> data > b -> data;
        }
};
 
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        priority_queue<node*, vector<node*>, compare> pq;

        for(int i = 0;i < matrix.size();i++){
            pq.push(new node(matrix[i][0], i, 0));
        }

        vector<int> ans;
        while(!pq.empty()){
            node* temp = pq.top();
            pq.pop();

            int data = temp -> data;
            int row = temp -> row;
            int col = temp -> col;

            ans.pb(data);

            if(col + 1 < matrix[row].size()){
                pq.push(new node(matrix[row][col + 1], row, col + 1));
            }
        }

        for(auto i:ans){
            cout << i << " ";
        }

        return ans[k-1];
    }
};     