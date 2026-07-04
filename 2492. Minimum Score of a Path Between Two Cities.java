class Solution {

    public int minScore(
            int numberOfCities,
            int[][] roads
    ) {

        // Build adjacency list
        List<List<int[]>> graph =
                new ArrayList<>();

        for (int i = 0;
             i <= numberOfCities;
             i++) {

            graph.add(
                    new ArrayList<>()
            );
        }

        for (int[] road : roads) {

            int cityA = road[0];
            int cityB = road[1];
            int roadDistance = road[2];

            graph.get(cityA).add(
                    new int[]{
                            cityB,
                            roadDistance
                    }
            );

            graph.get(cityB).add(
                    new int[]{
                            cityA,
                            roadDistance
                    }
            );
        }

        boolean[] visited =
                new boolean[numberOfCities + 1];

        Queue<Integer> bfsQueue =
                new LinkedList<>();

        bfsQueue.offer(1);
        visited[1] = true;

        int minimumScore =
                Integer.MAX_VALUE;

        // BFS traversal
        while (!bfsQueue.isEmpty()) {

            int currentCity =
                    bfsQueue.poll();

            for (int[] edge :
                    graph.get(currentCity)) {

                int nextCity = edge[0];
                int roadDistance = edge[1];

                // Update minimum edge weight
                minimumScore = Math.min(
                        minimumScore,
                        roadDistance
                );

                if (!visited[nextCity]) {

                    visited[nextCity] = true;

                    bfsQueue.offer(nextCity);
                }
            }
        }

        return minimumScore;
    }
}
