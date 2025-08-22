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
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        map<int, int> mp;

        while(head != NULL){
            mp[head -> val]++;
            head = head -> next;
        }

        ListNode* ansHead = NULL;
        ListNode* ansTail = NULL;

        for(auto [node, freq]:mp){
            if(freq == 1){
                ListNode* Node = new ListNode(node);
                if(ansHead == NULL && ansTail == NULL){
                    ansHead = Node;
                    ansTail = Node;
                }
                else{
                    ansTail -> next = Node;
                    ansTail = Node;
                }
            }
        }

        for(ListNode* Head = ansHead; Head != NULL;Head = Head -> next){
            cout << Head -> val << " -> ";
        }
        cout << "X";

        return ansHead;
    }
};