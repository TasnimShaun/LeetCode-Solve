class Solution:

    def mirror(self, left, right):

        # Both null
        if not left and not right:
            return True

        # One null
        if not left or not right:
            return False

        # Values differ
        if left.val != right.val:
            return False

        return (
            self.mirror(left.left, right.right) and
            self.mirror(left.right, right.left)
        )

    def isSymmetric(self, root):

        if not root:
            return True

        return self.mirror(root.left, root.right)
