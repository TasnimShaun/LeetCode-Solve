class Solution {
public:

    int assignEdgeWeights(vector<vector<int>>& edgeList) {

        const int MODULO = 1e9 + 7;

        int totalNodes = edgeList.size() + 1;

        // Adjacency list representation of the tree
        vector<vector<int>> adjacencyList(
            totalNodes + 1
        );

        // Build the graph
        for (const auto& edge : edgeList) {

            int sourceNode = edge[0];
            int destinationNode = edge[1];

            adjacencyList[sourceNode].push_back(
                destinationNode
            );

            adjacencyList[destinationNode].push_back(
                sourceNode
            );
        }

        // Stores the maximum depth of the tree
        int maximumDepth = 0;

        // {node, depth}
        stack<pair<int, int>> dfsStack;

        dfsStack.push({1, 0});

        vector<bool> visitedNodes(
            totalNodes + 1,
            false
        );

        visitedNodes[1] = true;

        // Iterative DFS
        while (!dfsStack.empty()) {

            auto [currentNode, currentDepth] =
                dfsStack.top();

            dfsStack.pop();

            maximumDepth = max(
                maximumDepth,
                currentDepth
            );

            for (int neighborNode :
                 adjacencyList[currentNode]) {

                if (!visitedNodes[neighborNode]) {

                    visitedNodes[neighborNode] = true;

                    dfsStack.push(
                        {
                            neighborNode,
                            currentDepth + 1
                        }
                    );
                }
            }
        }

        // Fast modular exponentiation
        long long answer = 1;

        long long base = 2;

        int exponent = maximumDepth - 1;

        while (exponent > 0) {

            if (exponent & 1) {
                answer =
                    (answer * base) % MODULO;
            }

            base =
                (base * base) % MODULO;

            exponent >>= 1;
        }

        return (int)answer;
    }
};
