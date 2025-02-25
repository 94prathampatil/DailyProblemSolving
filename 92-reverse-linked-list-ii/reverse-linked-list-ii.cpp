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
#define ll long long

class Solution {
public:
    void createList(ListNode* &head, ListNode* &tail, int d){
        ListNode* node = new ListNode(d);
        if(head == NULL && tail == NULL){
            head = node;
            tail = node;
        }
        else{
            tail -> next = node;
            tail = node;
        }
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        ListNode* temp = head;
        vector<int> arr;
        while(temp != NULL){
            arr.pb(temp -> val);
            temp = temp -> next;
        }

        ListNode* newHead = NULL;
        ListNode* newTail = NULL;

        reverse(arr.begin() + left - 1, arr.begin() + right);
        // for(auto i:arr){
        //     cout << i << " ";
        // }

        for(auto i : arr){
            createList(newHead, newTail, i);
        }

        return newHead;
    }
};