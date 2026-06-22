   class Solution:
    def isSameTree(self, p, q):

        # Both nodes are null
        if not p and not q:
            return True

        # One is null
        if not p or not q:
            return False

        # Values differ
        if p.val != q.val:
            return False

        return (
            self.isSameTree(p.left, q.left) and
            self.isSameTree(p.right, q.right)
        )
