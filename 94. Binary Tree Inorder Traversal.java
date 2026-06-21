class Solution {

    private List<Integer> result = new ArrayList<>();

    private void inorder(TreeNode root) {

        // Base case
        if (root == null) {
            return;
        }

        // Traverse left subtree
        inorder(root.left);

        // Visit current node
        result.add(root.val);

        // Traverse right subtree
        inorder(root.right);
    }

    public List<Integer> inorderTraversal(TreeNode root) {

        inorder(root);

        return result;
    }
}
