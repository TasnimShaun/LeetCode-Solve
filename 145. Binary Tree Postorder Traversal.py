class Solution:
    def postorderTraversal(self, root):

        result = []

        def postorder(node):

            # Base case
            if not node:
                return

            # Left
            postorder(node.left)

            # Right
            postorder(node.right)

            # Root
            result.append(node.val)

        postorder(root)

        return result
