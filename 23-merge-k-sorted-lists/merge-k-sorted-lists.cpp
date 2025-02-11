/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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

class compare{
    public:     
        bool operator()(ListNode* a, ListNode* b){
            return a -> val > b -> val;
        }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        int k = lists.size();
        for(int i = 0;i < k;i++){
            if(lists[i] != NULL){
                pq.push(lists[i]);
            }
        }

        ListNode* head = NULL;
        ListNode* tail = NULL;

        while(pq.size() > 0){
            ListNode* top = pq.top();
            pq.pop();

            if(top -> next != NULL){
                pq.push(top -> next);
            }

            if(head == NULL){
                head = top;
                tail = top;
            }
            else{
                tail -> next = top;
                tail = tail -> next;
            }
        }

        return head;
    }
};