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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int end = 0;
        ListNode* curr = head;
        while(end != n && curr != NULL){
            end++;
            curr = curr -> next;
        }

        if (curr == NULL)
        {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        ListNode* start = head;
        ListNode* prev = NULL;

        while(curr != NULL){
            prev = start;
            start = start -> next;
            curr = curr -> next;
        }

        prev -> next = start -> next;
        delete start;

        return head;
    }
};