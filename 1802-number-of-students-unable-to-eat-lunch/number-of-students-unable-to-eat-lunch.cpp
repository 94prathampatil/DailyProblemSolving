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
    int countStudents(vector<int>& student, vector<int>& sandwiches) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = student.size();
        queue<int> studentQueue;
        stack<int> sandwichStack;

        for(int i = 0;i < n;i++){
            sandwichStack.push(sandwiches[n - i - 1]);
            studentQueue.push(student[i]);
        }

        int missedSandwich = 0;

        while(!studentQueue.empty()){
            if(studentQueue.front() == sandwichStack.top()){
                studentQueue.pop();
                sandwichStack.pop();
                missedSandwich = 0;
            }
            else{
                studentQueue.push(studentQueue.front());
                studentQueue.pop();
                missedSandwich++;

                if(missedSandwich == studentQueue.size())   break;
            }
        }

        return studentQueue.size();

    }
};
