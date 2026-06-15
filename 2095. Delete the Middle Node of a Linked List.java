class Solution {

    public ListNode deleteMiddle(
            ListNode headNode) {

        // If there is only one node
        if (headNode == null ||
            headNode.next == null) {

            return null;
        }

        ListNode slowPointer =
                headNode;

        ListNode fastPointer =
                headNode;

        ListNode previousNode =
                null;

        // Find the middle node
        while (fastPointer != null &&
               fastPointer.next != null) {

            previousNode =
                    slowPointer;

            slowPointer =
                    slowPointer.next;

            fastPointer =
                    fastPointer.next.next;
        }

        // Delete the middle node
        previousNode.next =
                slowPointer.next;

        return headNode;
    }
}
