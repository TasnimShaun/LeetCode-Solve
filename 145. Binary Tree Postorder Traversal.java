class Solution {

    private List<Integer> result = new ArrayList<>();

    private void postorder(TreeNode root) {

        // Base case
        if (root == null) {
            return;
        }

        // Traverse left subtree
        postorder(root.left);

        // Traverse right subtree
        postorder(root.right);

        // Visit current node
        result.add(root.val);
    }

    public List<Integer> postorderTraversal(TreeNode root) {

        postorder(root);

        return result;
    }
}
