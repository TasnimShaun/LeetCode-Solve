class Solution:
    def pathsWithMaxScore(self, board: List[str]) -> List[int]:

        MOD = 1000000007
        n = len(board)

        nextScore = [-1] * (n + 1)
        nextWays = [0] * (n + 1)

        for row in range(n - 1, -1, -1):

            currentScore = [-1] * (n + 1)
            currentWays = [0] * (n + 1)

            for col in range(n - 1, -1, -1):

                cell = board[row][col]

                if cell == 'X':
                    continue

                if cell == 'S':
                    currentScore[col] = 0
                    currentWays[col] = 1
                    continue

                bestScore = max(
                    nextScore[col],
                    currentScore[col + 1],
                    nextScore[col + 1]
                )

                if bestScore == -1:
                    continue

                ways = 0

                if nextScore[col] == bestScore:
                    ways += nextWays[col]

                if currentScore[col + 1] == bestScore:
                    ways += currentWays[col + 1]

                if nextScore[col + 1] == bestScore:
                    ways += nextWays[col + 1]

                value = 0 if cell == 'E' else int(cell)

                currentScore[col] = bestScore + value
                currentWays[col] = ways % MOD

            nextScore = currentScore
            nextWays = currentWays

        if nextScore[0] == -1:
            return [0, 0]

        return [nextScore[0], nextWays[0]]
