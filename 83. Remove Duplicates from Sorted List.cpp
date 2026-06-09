class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        // Empty list হলে return
        if(head == NULL)
            return head;

        ListNode* temp = head;

        while(temp != NULL && temp->next != NULL)
        {
            // Duplicate পাওয়া গেছে
            if(temp->val == temp->next->val)
            {
                ListNode* deleteNode = temp->next;

                // duplicate node skip করো
                temp->next = temp->next->next;

                delete deleteNode;
            }
            else
            {
                temp = temp->next;
            }
        }

        return head;
    }
};
