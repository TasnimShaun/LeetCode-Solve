class Solution:
    def findMaxPathScore(
        self,
        edges: List[List[int]],
        online: List[bool],
        k: int
    ) -> int:

        n = len(online)

        # Build graph
        graph = [[] for _ in range(n)]
        indegree = [0] * n

        for u, v, w in edges:
            graph[u].append((v, w))
            indegree[v] += 1

        # Topological sort (Kahn's algorithm)
        q = deque(i for i in range(n) if indegree[i] == 0)
        topo = []

        while q:
            node = q.popleft()
            topo.append(node)

            for nxt, _ in graph[node]:
                indegree[nxt] -= 1
                if indegree[nxt] == 0:
                    q.append(nxt)

        # Check if a given minimum edge weight is possible
        def canReach(limit: int) -> bool:

            INF = float('inf')
            dist = [INF] * n
            dist[0] = 0

            for node in topo:

                if dist[node] == INF:
                    continue

                # skip offline intermediate nodes
                if node != 0 and node != n - 1 and not online[node]:
                    continue

                for nxt, w in graph[node]:

                    if w < limit:
                        continue

                    if nxt != n - 1 and not online[nxt]:
                        continue

                    dist[nxt] = min(
                        dist[nxt],
                        dist[node] + w
                    )

            return dist[n - 1] <= k

        # Binary search on answer
        left, right = 0, 10**9
        ans = -1

        while left <= right:

            mid = (left + right) // 2

            if canReach(mid):
                ans = mid
                left = mid + 1
            else:
                right = mid - 1

        return ans
        
