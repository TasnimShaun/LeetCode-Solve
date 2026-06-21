class Solution:
    def inorderTraversal(self, root):

        result = []

        def inorder(node):

            # Base case
            if not node:
                return

            # Traverse left subtree
            inorder(node.left)

            # Visit current node
            result.append(node.val)

            # Traverse right subtree
            inorder(node.right)

        inorder(root)

        return result
