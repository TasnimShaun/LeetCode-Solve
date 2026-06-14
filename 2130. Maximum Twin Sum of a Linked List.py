# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:

    def pairSum(
        self,
        head_node: Optional[ListNode]
    ) -> int:

        # Find the middle of the linked list
        slow_pointer = head_node
        fast_pointer = head_node

        while fast_pointer and fast_pointer.next:

            slow_pointer = (
                slow_pointer.next
            )

            fast_pointer = (
                fast_pointer.next.next
            )

        # Reverse the second half
        previous_node = None

        while slow_pointer:

            next_node = (
                slow_pointer.next
            )

            slow_pointer.next = (
                previous_node
            )

            previous_node = (
                slow_pointer
            )

            slow_pointer = next_node

        maximum_twin_sum = 0

        first_half_node = head_node

        second_half_node = previous_node

        # Calculate twin sums
        while second_half_node:

            maximum_twin_sum = max(
                maximum_twin_sum,
                first_half_node.val +
                second_half_node.val
            )

            first_half_node = (
                first_half_node.next
            )

            second_half_node = (
                second_half_node.next
            )

        return maximum_twin_sum
