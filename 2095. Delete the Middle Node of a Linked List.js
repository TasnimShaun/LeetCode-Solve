/**
 * @param {ListNode} headNode
 * @return {ListNode}
 */
var deleteMiddle = function(headNode) {

    // If there is only one node
    if (!headNode || !headNode.next) {
        return null;
    }

    let slowPointer = headNode;

    let fastPointer = headNode;

    let previousNode = null;

    // Find the middle node
    while (fastPointer &&
           fastPointer.next) {

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
};
