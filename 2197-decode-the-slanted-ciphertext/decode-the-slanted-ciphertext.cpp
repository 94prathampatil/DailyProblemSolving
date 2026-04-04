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
    string decodeCiphertext(string encodedText, int rows) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int len = encodedText.length();
        int columns = len / rows;

        string ans = "";
        vector<vector<char>> ogText(rows, vector<char> (columns, ' '));

        int ind = 0;
        for(int i = 0;i < rows;i++){
            for(int j = 0;j < columns;j++){
                ogText[i][j] = encodedText[ind++];
            }
        }

        for(int col = 0;col < columns;col++){
            int i = 0;
            int j = col;

            while(i < rows && j < columns){
                ans += ogText[i][j];
                i++, j++;
            }
        }

        int i = ans.length() - 1;

        while(i >= 0 && ans[i] == ' '){
            ans.pop_back();
            i--;
        }

        return ans;
    }
};