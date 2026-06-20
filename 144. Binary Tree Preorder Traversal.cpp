class Solution {
public:
    vector<int> result;

    void preorder(TreeNode* root) {

        // Base case
        if (root == nullptr) {
            return;
        }

        // Visit root
        result.push_back(root->val);

        // Traverse left subtree
        preorder(root->left);

        // Traverse right subtree
        preorder(root->right);
    }

    vector<int> preorderTraversal(TreeNode* root) {

        preorder(root);

        return result;
    }
};
