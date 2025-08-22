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
        if(!head)   return head;


        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        ListNode* curr = head;


        while(curr){
            bool dup = false;

            while(curr -> next && curr -> val == curr -> next -> val){
                dup = true;
                curr = curr -> next;
            }

            if(dup){
                prev -> next = curr -> next;
            }
            else{
                prev  = prev -> next;
            }

            curr = curr -> next;
        }

        ListNode* ansNode = dummy -> next;
        delete dummy;

        return ansNode;
    }
};