class Solution {
public:

    static const int MODULO = 1000000007;

    // Depth of each node from the root
    vector<int> nodeDepth;

    // Binary lifting table
    vector<vector<int>> ancestors;

    // Adjacency list of the tree
    vector<vector<int>> adjacencyList;

    int maxLog;

    // DFS to calculate depths and ancestors
    void buildLCA(int currentNode,
                  int parentNode) {

        ancestors[currentNode][0] = parentNode;

        // Fill binary lifting table
        for (int level = 1;
             level < maxLog;
             level++) {

            ancestors[currentNode][level] =
                ancestors[
                    ancestors[currentNode][level - 1]
                ][level - 1];
        }

        for (int neighborNode :
             adjacencyList[currentNode]) {

            if (neighborNode == parentNode)
                continue;

            nodeDepth[neighborNode] =
                nodeDepth[currentNode] + 1;

            buildLCA(
                neighborNode,
                currentNode
            );
        }
    }

    // Find Lowest Common Ancestor
    int findLCA(int firstNode,
                int secondNode) {

        // Ensure firstNode is deeper
        if (nodeDepth[firstNode] <
            nodeDepth[secondNode]) {

            swap(firstNode,
                 secondNode);
        }

        int depthDifference =
            nodeDepth[firstNode] -
            nodeDepth[secondNode];

        // Lift firstNode up
        for (int level = maxLog - 1;
             level >= 0;
             level--) {

            if ((depthDifference >> level) & 1) {

                firstNode =
                    ancestors[firstNode][level];
            }
        }

        if (firstNode == secondNode)
            return firstNode;

        // Lift both nodes together
        for (int level = maxLog - 1;
             level >= 0;
             level--) {

            if (ancestors[firstNode][level] !=
                ancestors[secondNode][level]) {

                firstNode =
                    ancestors[firstNode][level];

                secondNode =
                    ancestors[secondNode][level];
            }
        }

        return ancestors[firstNode][0];
    }

    vector<int> assignEdgeWeights(
        vector<vector<int>>& edgeList,
        vector<vector<int>>& queryList) {

        int totalNodes =
            edgeList.size() + 1;

        // Determine required log value
        maxLog = 17;

        while ((1 << maxLog) <= totalNodes)
            maxLog++;

        // Build graph
        adjacencyList.assign(
            totalNodes + 1,
            {}
        );

        for (auto& edge : edgeList) {

            int sourceNode = edge[0];
            int destinationNode = edge[1];

            adjacencyList[sourceNode]
                .push_back(destinationNode);

            adjacencyList[destinationNode]
                .push_back(sourceNode);
        }

        nodeDepth.assign(
            totalNodes + 1,
            0
        );

        ancestors.assign(
            totalNodes + 1,
            vector<int>(maxLog, 1)
        );

        // Root the tree at node 1
        buildLCA(1, 1);

        // Precompute powers of 2
        vector<int> powerOfTwo(
            totalNodes + 1,
            1
        );

        for (int exponent = 1;
             exponent <= totalNodes;
             exponent++) {

            powerOfTwo[exponent] =
                (long long)
                powerOfTwo[exponent - 1]
                * 2 % MODULO;
        }

        vector<int> answers;

        for (auto& query : queryList) {

            int firstNode = query[0];
            int secondNode = query[1];

            int commonAncestor =
                findLCA(
                    firstNode,
                    secondNode
                );

            int pathLength =
                nodeDepth[firstNode] +
                nodeDepth[secondNode] -
                2 * nodeDepth[commonAncestor];

            if (pathLength == 0) {

                answers.push_back(0);
            }
            else {

                answers.push_back(
                    powerOfTwo[pathLength - 1]
                );
            }
        }

        return answers;
    }
};
