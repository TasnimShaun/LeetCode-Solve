from collections import deque
from typing import List

class Solution:
    def minScore(self, n: int, roads: List[List[int]]) -> int:

        # Build adjacency list
        graph = [[] for _ in range(n + 1)]

        for a, b, distance in roads:
            graph[a].append((b, distance))
            graph[b].append((a, distance))

        visited = [False] * (n + 1)

        q = deque()
        q.append(1)
        visited[1] = True

        minimum_score = float('inf')

        # BFS traversal
        while q:

            city = q.popleft()

            for next_city, distance in graph[city]:

                # update minimum edge in connected component
                minimum_score = min(minimum_score, distance)

                if not visited[next_city]:
                    visited[next_city] = True
                    q.append(next_city)

        return minimum_score
