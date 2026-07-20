class Solution {
public:
    ListNode* removeElements(ListNode* head, int value) {
        if(head == NULL)
            return head;

        while(head != NULL && head->val == value)
        {
            head = head->next;
        }
        ListNode* temp = head;
        while(temp != NULL && temp->next != NULL)
        {
            if(temp->next->val == value)
                temp->next = temp->next->next;
            else
                temp = temp->next;
        }
        return head;
    }
};
