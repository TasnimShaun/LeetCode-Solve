class Solution {
public:
    ListNode* deleteMiddle(ListNode* headNode) {

        if (!headNode || !headNode->next) {
            return nullptr;
        }

        ListNode* slowPointer = headNode;
        ListNode* fastPointer = headNode;
        ListNode* previousNode = nullptr;

        while (fastPointer &&
               fastPointer->next) {

            previousNode = slowPointer;
            slowPointer = slowPointer->next;
            fastPointer = fastPointer->next->next;
        }

        previousNode->next = slowPointer->next;

        return headNode;
    }
};
