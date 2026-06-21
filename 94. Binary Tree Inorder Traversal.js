
var inorderTraversal = function(root) {

    const result = [];

    function inorder(node) {

        // Base case
        if (!node) {
            return;
        }

        // Left
        inorder(node.left);

        // Root
        result.push(node.val);

        // Right
        inorder(node.right);
    }

    inorder(root);

    return result;
};
