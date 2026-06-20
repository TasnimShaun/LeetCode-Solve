class Solution {

    private List<Integer> result = new ArrayList<>();

    private void preorder(TreeNode root) {

        if (root == null) {
            return;
        }

        result.add(root.val);

        preorder(root.left);
        preorder(root.right);
    }

    public List<Integer> preorderTraversal(TreeNode root) {

        preorder(root);

        return result;
    }
}
