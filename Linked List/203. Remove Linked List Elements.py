class Solution:
    def removeElements(self, head, value):

        if head is None:
            return head

        while head is not None and head.val == value:
            head = head.next

        temp = head

        while temp is not None and temp.next is not None:

            if temp.next.val == value:
                temp.next = temp.next.next
            else:
                temp = temp.next

        return head
