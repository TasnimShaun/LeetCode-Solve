from collections import deque
import heapq

class Solution:
    def maximumSafenessFactor(self, grid):

        n = len(grid)

        if grid[0][0] == 1 or grid[n-1][n-1] == 1:
            return 0

        queue = deque()

        # Multi-source BFS
        for row in range(n):
            for col in range(n):
                if grid[row][col] == 1:
                    queue.append((row, col))

        directions = [(-1,0),(1,0),(0,-1),(0,1)]

        while queue:

            row, col = queue.popleft()

            distance = grid[row][col]

            for dr, dc in directions:

                newRow = row + dr
                newCol = col + dc

                if (0 <= newRow < n and
                    0 <= newCol < n and
                    grid[newRow][newCol] == 0):

                    grid[newRow][newCol] = distance + 1
                    queue.append((newRow, newCol))

        pq = []

        heapq.heappush(pq, (-grid[0][0], 0, 0))
        grid[0][0] *= -1

        while pq:

            safe, row, col = heapq.heappop(pq)
            safe = -safe

            if row == n - 1 and col == n - 1:
                return safe - 1

            for dr, dc in directions:

                newRow = row + dr
                newCol = col + dc

                if (0 <= newRow < n and
                    0 <= newCol < n and
                    grid[newRow][newCol] > 0):

                    heapq.heappush(
                        pq,
                        (-min(safe, grid[newRow][newCol]),
                         newRow,
                         newCol)
                    )

                    grid[newRow][newCol] *= -1

        return 0
