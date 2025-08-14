class Solution {
public:
    void fillStack(ListNode* head, stack<int> &st) {
        while (head != NULL) {
            st.push(head->val);
            head = head->next;
        }
    }

    void createList(ListNode* &head, ListNode* &tail, int value) {
        ListNode* node = new ListNode(value);
        if (head == NULL) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    ListNode* rev(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while (curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> st1, st2;
        fillStack(l1, st1);
        fillStack(l2, st2);

        ListNode* head = NULL;
        ListNode* tail = NULL;
        int carry = 0;

        while (!st1.empty() || !st2.empty() || carry) {
            int sum = carry;
            if (!st1.empty()) { sum += st1.top(); st1.pop(); }
            if (!st2.empty()) { sum += st2.top(); st2.pop(); }

            int digit = sum % 10;   
            carry = sum / 10;       
            createList(head, tail, digit);
        }

        return rev(head);
    }
};
