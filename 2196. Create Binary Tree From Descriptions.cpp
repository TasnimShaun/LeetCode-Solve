class Solution {
public:

    TreeNode* createBinaryTree(
        vector<vector<int>>& nodeDescriptions) {

        // Maps node value -> TreeNode pointer
        unordered_map<int, TreeNode*> nodeMap;

        // Stores all nodes that appear as children
        unordered_set<int> childNodes;

        for (auto& description : nodeDescriptions) {

            int parentValue = description[0];
            int childValue = description[1];
            int isLeftChild = description[2];

            // Create parent node if it doesn't exist
            if (!nodeMap.count(parentValue))
                nodeMap[parentValue] =
                    new TreeNode(parentValue);

            // Create child node if it doesn't exist
            if (!nodeMap.count(childValue))
                nodeMap[childValue] =
                    new TreeNode(childValue);

            // Mark this node as a child
            childNodes.insert(childValue);

            // Connect parent with child
            if (isLeftChild == 1)
                nodeMap[parentValue]->left =
                    nodeMap[childValue];
            else
                nodeMap[parentValue]->right =
                    nodeMap[childValue];
        }

        // Root node is the one that never appears as a child
        for (auto& [nodeValue, nodePointer] : nodeMap) {

            if (!childNodes.count(nodeValue))
                return nodePointer;
        }

        return nullptr;
    }
};
