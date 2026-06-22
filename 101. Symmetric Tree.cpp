class Solution {
public:

    bool mirror(TreeNode* left, TreeNode* right) {

        // Both null
        if (left == nullptr && right == nullptr) {
            return true;
        }

        // One null
        if (left == nullptr || right == nullptr) {
            return false;
        }

        // Values differ
        if (left->val != right->val) {
            return false;
        }

        return mirror(left->left, right->right) &&
               mirror(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) {

        if (root == nullptr) {
            return true;
        }

        return mirror(root->left, root->right);
    }
};
