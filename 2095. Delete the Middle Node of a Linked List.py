class Solution:
    def deleteMiddle(
        self,
        head_node: Optional[ListNode]
    ) -> Optional[ListNode]:

        # If there is only one node,
        # deleting the middle makes the list empty
        if not head_node or not head_node.next:
            return None

        slow_pointer = head_node
        fast_pointer = head_node
        previous_node = None

        # Find the middle node
        while fast_pointer and fast_pointer.next:

            previous_node = slow_pointer

            slow_pointer = slow_pointer.next

            fast_pointer = (
                fast_pointer.next.next
            )

        # Delete the middle node
        previous_node.next = (
            slow_pointer.next
        )

        return head_node
