class Solution {
public:
    vector<int> result;

    void postorder(TreeNode* root) {

        // Base case
        if (root == nullptr) {
            return;
        }

        // Traverse left subtree
        postorder(root->left);

        // Traverse right subtree
        postorder(root->right);

        // Visit current node
        result.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {

        postorder(root);

        return result;
    }
};
