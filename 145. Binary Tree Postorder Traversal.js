/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var postorderTraversal = function(root) {

    const result = [];

    function postorder(node) {

        // Base case
        if (!node) {
            return;
        }

        // Left
        postorder(node.left);

        // Right
        postorder(node.right);

        // Root
        result.push(node.val);
    }

    postorder(root);

    return result;
};
