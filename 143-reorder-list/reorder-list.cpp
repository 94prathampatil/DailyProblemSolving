class Solution {
public:
    ListNode* reverseList(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL) return;

        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = reverseList(slow->next);
        slow->next = NULL;


        ListNode* first = head;

        while(second){
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;
            
            first = temp1;
            second = temp2;
        }


    }
};
