class Solution {
public:
    int countCompleteComponents(
        int numberOfNodes,
        vector<vector<int>>& edges
    ) {

        // Build adjacency list
        vector<vector<int>> graph(numberOfNodes);

        for (const auto& edge : edges) {

            int nodeA = edge[0];
            int nodeB = edge[1];

            graph[nodeA].push_back(nodeB);
            graph[nodeB].push_back(nodeA);
        }

        bitset<51> visited;

        int completeComponents = 0;

        for (int node = 0; node < numberOfNodes; node++) {

            if (visited.test(node)) {
                continue;
            }

            int vertices = 0;
            int degreeSum = 0;

            auto dfs = [&](auto&& dfs, int currentNode) -> void {

                visited.set(currentNode);

                vertices++;

                degreeSum += graph[currentNode].size();

                for (int neighbor : graph[currentNode]) {

                    if (!visited.test(neighbor)) {
                        dfs(dfs, neighbor);
                    }
                }
            };

            dfs(dfs, node);

            // A complete graph with V vertices
            // has V * (V - 1) total degree.
            if (degreeSum == vertices * (vertices - 1)) {
                completeComponents++;
            }
        }

        return completeComponents;
    }
};
