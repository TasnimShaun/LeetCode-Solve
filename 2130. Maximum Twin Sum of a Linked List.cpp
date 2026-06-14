class Solution {
public:

    int pairSum(ListNode* headNode) {

        // Find the middle of the linked list
        ListNode* slowPointer = headNode;
        ListNode* fastPointer = headNode;

        while (fastPointer &&
               fastPointer->next) {

            slowPointer =
                slowPointer->next;

            fastPointer =
                fastPointer->next->next;
        }

        // Reverse the second half of the list
        ListNode* previousNode = nullptr;

        while (slowPointer) {

            ListNode* nextNode =
                slowPointer->next;

            slowPointer->next =
                previousNode;

            previousNode =
                slowPointer;

            slowPointer =
                nextNode;
        }

        int maximumTwinSum = 0;

        ListNode* firstHalfNode =
            headNode;

        ListNode* secondHalfNode =
            previousNode;

        // Calculate twin sums
        while (secondHalfNode) {

            maximumTwinSum = max(
                maximumTwinSum,
                firstHalfNode->val +
                secondHalfNode->val
            );

            firstHalfNode =
                firstHalfNode->next;

            secondHalfNode =
                secondHalfNode->next;
        }

        return maximumTwinSum;
    }
};
