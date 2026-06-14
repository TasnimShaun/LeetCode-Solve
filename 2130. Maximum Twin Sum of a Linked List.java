class Solution {

    public int pairSum(ListNode headNode) {

        // Find the middle of the linked list
        ListNode slowPointer = headNode;
        ListNode fastPointer = headNode;

        while (fastPointer != null &&
               fastPointer.next != null) {

            slowPointer = slowPointer.next;

            fastPointer = fastPointer.next.next;
        }

        // Reverse the second half of the linked list
        ListNode previousNode = null;

        while (slowPointer != null) {

            ListNode nextNode =
                    slowPointer.next;

            slowPointer.next =
                    previousNode;

            previousNode =
                    slowPointer;

            slowPointer =
                    nextNode;
        }

        // Store the maximum twin sum
        int maximumTwinSum = 0;

        ListNode firstHalfPointer =
                headNode;

        ListNode secondHalfPointer =
                previousNode;

        // Calculate twin sums
        while (secondHalfPointer != null) {

            int currentTwinSum =
                    firstHalfPointer.val +
                    secondHalfPointer.val;

            maximumTwinSum = Math.max(
                    maximumTwinSum,
                    currentTwinSum
            );

            firstHalfPointer =
                    firstHalfPointer.next;

            secondHalfPointer =
                    secondHalfPointer.next;
        }

        return maximumTwinSum;
    }
}
