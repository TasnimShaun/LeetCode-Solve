class Solution {
public:
    int findMaxPathScore(
        vector<vector<int>>& edges,
        vector<bool>& isOnline,
        long long maxCost
    ) {

        int n = isOnline.size();

        // adjacency list: (to, weight)
        vector<vector<pair<int,int>>> adj(n);

        // indegree for topo sort
        vector<int> indegree(n, 0);

        for (auto &edge : edges) {

            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v, w});
            indegree[v]++;
        }

        // Kahn's algorithm for topological order
        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topoOrder;

        while (!q.empty()) {

            int node = q.front();
            q.pop();

            topoOrder.push_back(node);

            for (auto &[nextNode, weight] : adj[node]) {

                indegree[nextNode]--;

                if (indegree[nextNode] == 0) {
                    q.push(nextNode);
                }
            }
        }

        // check if we can reach end with given minEdgeWeight
        auto canReach = [&](int minEdgeWeight) {

            const long long INF = (1LL << 60);

            vector<long long> dist(n, INF);
            dist[0] = 0;

            for (int node : topoOrder) {

                if (dist[node] == INF) continue;

                // skip offline intermediate nodes
                if (node != 0 && node != n - 1 && !isOnline[node]) {
                    continue;
                }

                for (auto &[nextNode, weight] : adj[node]) {

                    if (weight < minEdgeWeight) continue;

                    if (nextNode != n - 1 && !isOnline[nextNode]) {
                        continue;
                    }

                    dist[nextNode] = min(
                        dist[nextNode],
                        dist[node] + weight
                    );
                }
            }

            return dist[n - 1] <= maxCost;
        };

        // binary search on answer
        int left = 0, right = 1e9;
        int bestAnswer = -1;

        while (left <= right) {

            int mid = left + (right - left) / 2;

            if (canReach(mid)) {
                bestAnswer = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return bestAnswer;
    }
};
