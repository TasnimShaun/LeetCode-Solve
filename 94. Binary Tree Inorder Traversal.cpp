
class Solution {
public:
    vector<int> result;

    void inorder(TreeNode* root) {

        // Base case
        if (root == nullptr) {
            return;
        }

        // Traverse left subtree
        inorder(root->left);

        // Visit current node
        result.push_back(root->val);

        // Traverse right subtree
        inorder(root->right);
    }

    vector<int> inorderTraversal(TreeNode* root) {

        inorder(root);

        return result;
    }
};
