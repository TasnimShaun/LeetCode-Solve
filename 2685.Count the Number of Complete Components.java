class Solution {

    private List<Integer>[] graph;

    private boolean[] visited;

    private int vertices;

    private int degreeSum;

    public int countCompleteComponents(
            int numberOfNodes,
            int[][] edges
    ) {

        graph = new ArrayList[numberOfNodes];

        for (int i = 0; i < numberOfNodes; i++) {
            graph[i] = new ArrayList<>();
        }

        // Build adjacency list
        for (int[] edge : edges) {

            int nodeA = edge[0];
            int nodeB = edge[1];

            graph[nodeA].add(nodeB);
            graph[nodeB].add(nodeA);
        }

        visited = new boolean[numberOfNodes];

        int completeComponents = 0;

        for (int node = 0; node < numberOfNodes; node++) {

            if (visited[node]) {
                continue;
            }

            vertices = 0;
            degreeSum = 0;

            dfs(node);

            if (degreeSum == vertices * (vertices - 1)) {
                completeComponents++;
            }
        }

        return completeComponents;
    }

    private void dfs(int currentNode) {

        visited[currentNode] = true;

        vertices++;

        degreeSum += graph[currentNode].size();

        for (int neighbor : graph[currentNode]) {

            if (!visited[neighbor]) {
                dfs(neighbor);
            }
        }
    }
}
