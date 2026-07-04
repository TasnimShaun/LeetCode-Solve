class Solution {
public:
    int minScore(
        int numberOfCities,
        vector<vector<int>>& roads
    ) {

        // Build adjacency list
        vector<vector<pair<int, int>>> graph(
            numberOfCities + 1
        );

        for (const auto& road : roads) {

            int cityA = road[0];
            int cityB = road[1];
            int roadDistance = road[2];

            graph[cityA].push_back(
                {cityB, roadDistance}
            );

            graph[cityB].push_back(
                {cityA, roadDistance}
            );
        }

        vector<bool> visited(
            numberOfCities + 1,
            false
        );

        queue<int> bfsQueue;

        bfsQueue.push(1);
        visited[1] = true;

        int minimumScore = INT_MAX;

        // BFS traversal
        while (!bfsQueue.empty()) {

            int currentCity = bfsQueue.front();
            bfsQueue.pop();

            for (const auto& edge :
                 graph[currentCity]) {

                int nextCity = edge.first;
                int roadDistance = edge.second;

                // Update minimum edge weight
                minimumScore = min(
                    minimumScore,
                    roadDistance
                );

                if (!visited[nextCity]) {

                    visited[nextCity] = true;

                    bfsQueue.push(nextCity);
                }
            }
        }

        return minimumScore;
    }
};
