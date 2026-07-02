from collections import deque
from typing import List

class Solution:
    def findSafeWalk(self, grid: List[List[int]], health: int) -> bool:

        rows = len(grid)
        cols = len(grid[0])

        cost = [[float("inf")] * cols for _ in range(rows)]

        dq = deque()

        cost[0][0] = grid[0][0]
        dq.appendleft((0, 0))

        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

        while dq:

            row, col = dq.popleft()

            for dr, dc in directions:

                newRow = row + dr
                newCol = col + dc

                if newRow < 0 or newRow >= rows or newCol < 0 or newCol >= cols:
                    continue

                newHealthLoss = cost[row][col] + grid[newRow][newCol]

                if newHealthLoss < cost[newRow][newCol]:

                    cost[newRow][newCol] = newHealthLoss

                    if grid[newRow][newCol] == 0:
                        dq.appendleft((newRow, newCol))
                    else:
                        dq.append((newRow, newCol))

        return cost[rows - 1][cols - 1] < health
