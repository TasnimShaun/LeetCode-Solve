var pairSum = function(headNode) {

    // Find the middle of the linked list
    let slowPointer = headNode;
    let fastPointer = headNode;

    while (fastPointer && fastPointer.next) {

        slowPointer = slowPointer.next;

        fastPointer = fastPointer.next.next;
    }

    // Reverse the second half of the list
    let previousNode = null;

    while (slowPointer) {

        let nextNode = slowPointer.next;

        slowPointer.next = previousNode;

        previousNode = slowPointer;

        slowPointer = nextNode;
    }

    // Store the maximum twin sum
    let maximumTwinSum = 0;

    let firstHalfPointer = headNode;

    let secondHalfPointer = previousNode;

    // Compare corresponding nodes
    while (secondHalfPointer) {

        let currentTwinSum =
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
};
