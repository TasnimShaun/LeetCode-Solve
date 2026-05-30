class Fenwick {

    int size;
    vector<int> tree;

public:

    Fenwick(int treeSize = 0)
        : size(treeSize), tree(treeSize + 1, 0) {}

    // Add value at a position
    void add(int index, int value) {

        for (; index <= size; index += index & -index) {
            tree[index] += value;
        }
    }

    // Prefix sum from 1 to index
    int prefixSum(int index) const {

        int total = 0;

        for (; index > 0; index -= index & -index) {
            total += tree[index];
        }

        return total;
    }

    // Find the position of the k-th occupied element
    int findKth(int kthPosition) const {

        int currentIndex = 0;

        int highestPower = 1;

        while ((highestPower << 1) <= size)
            highestPower <<= 1;

        for (int step = highestPower; step > 0; step >>= 1) {

            int nextIndex = currentIndex + step;

            if (nextIndex <= size &&
                tree[nextIndex] < kthPosition) {

                currentIndex = nextIndex;
                kthPosition -= tree[nextIndex];
            }
        }

        return currentIndex + 1;
    }
};

class SegmentTree {

    int size;

    vector<int> segmentTree;

    void updateNode(int node,
                    int leftBound,
                    int rightBound,
                    int targetPosition,
                    int value) {

        if (leftBound == rightBound) {
            segmentTree[node] = value;
            return;
        }

        int middle = (leftBound + rightBound) >> 1;

        if (targetPosition <= middle)
            updateNode(node << 1,
                       leftBound,
                       middle,
                       targetPosition,
                       value);
        else
            updateNode(node << 1 | 1,
                       middle + 1,
                       rightBound,
                       targetPosition,
                       value);

        segmentTree[node] =
            max(segmentTree[node << 1],
                segmentTree[node << 1 | 1]);
    }

    int rangeMaximum(int node,
                     int leftBound,
                     int rightBound,
                     int queryLeft,
                     int queryRight) const {

        if (queryLeft > rightBound ||
            queryRight < leftBound)
            return 0;

        if (queryLeft <= leftBound &&
            rightBound <= queryRight)
            return segmentTree[node];

        int middle = (leftBound + rightBound) >> 1;

        return max(
            rangeMaximum(node << 1,
                         leftBound,
                         middle,
                         queryLeft,
                         queryRight),

            rangeMaximum(node << 1 | 1,
                         middle + 1,
                         rightBound,
                         queryLeft,
                         queryRight)
        );
    }

public:

    SegmentTree(int treeSize = 0)
        : size(treeSize),
          segmentTree(4 * max(1, treeSize), 0) {}

    // Point update
    void setValue(int position, int value) {

        if (size == 0)
            return;

        updateNode(1,
                   0,
                   size - 1,
                   position,
                   value);
    }

    // Maximum value in a range
    int getMaximum(int left,
                   int right) const {

        if (size == 0 || left > right)
            return 0;

        return rangeMaximum(
            1,
            0,
            size - 1,
            left,
            right
        );
    }
};

class Solution {

public:

    vector<bool> getResults(vector<vector<int>>& queries) {

        int maximumCoordinate = 0;

        // Find maximum position used in queries
        for (auto& currentQuery : queries) {
            maximumCoordinate =
                max(maximumCoordinate,
                    currentQuery[1]);
        }

        int fenwickTreeSize =
            maximumCoordinate + 2;

        Fenwick fenwickTree(fenwickTreeSize);

        SegmentTree segmentTree(
            maximumCoordinate + 1);

        // Position 0 is initially occupied
        fenwickTree.add(1, 1);

        vector<bool> answers;

        answers.reserve(queries.size());

        for (auto& currentQuery : queries) {

            int queryType = currentQuery[0];

            int position = currentQuery[1];

            // Type 1 -> Insert obstacle
            if (queryType == 1) {

                int occupiedBefore =
                    fenwickTree.prefixSum(position);

                int leftObstacle =
                    fenwickTree.findKth(
                        occupiedBefore
                    ) - 1;

                int occupiedUntilCurrent =
                    fenwickTree.prefixSum(
                        position + 1
                    );

                int totalOccupied =
                    fenwickTree.prefixSum(
                        fenwickTreeSize
                    );

                int rightObstacle = -1;

                if (occupiedUntilCurrent <
                    totalOccupied) {

                    rightObstacle =
                        fenwickTree.findKth(
                            occupiedUntilCurrent + 1
                        ) - 1;
                }

                // Update gap ending at current position
                segmentTree.setValue(
                    position,
                    position - leftObstacle
                );

                // Update gap ending at right obstacle
                if (rightObstacle != -1) {

                    segmentTree.setValue(
                        rightObstacle,
                        rightObstacle - position
                    );
                }

                // Mark current position as occupied
                fenwickTree.add(
                    position + 1,
                    1
                );
            }

            // Type 2 -> Query
            else {

                int requiredSize =
                    currentQuery[2];

                int occupiedBefore =
                    fenwickTree.prefixSum(position);

                int leftObstacle =
                    fenwickTree.findKth(
                        occupiedBefore
                    ) - 1;

                int largestGap =
                    segmentTree.getMaximum(
                        0,
                        position
                    );

                answers.push_back(
                    (position - leftObstacle >= requiredSize)
                    ||
                    (largestGap >= requiredSize)
                );
            }
        }

        return answers;
    }
};
