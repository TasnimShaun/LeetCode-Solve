class Solution:
    def maxBuilding(self, n: int, restrictions: list[list[int]]) -> int:

        # Add building 1 and building n as restrictions
        restrictions.append([1, 0])
        restrictions.append([n, n - 1])

        # Sort restrictions by building index
        restrictions.sort()

        m = len(restrictions)

        # Left to Right pass
        # Ensure current restriction is reachable
        for i in range(1, m):
            restrictions[i][1] = min(
                restrictions[i][1],
                restrictions[i - 1][1] +
                (restrictions[i][0] - restrictions[i - 1][0])
            )

        # Right to Left pass
        # Tighten restrictions from the right side
        for i in range(m - 2, -1, -1):
            restrictions[i][1] = min(
                restrictions[i][1],
                restrictions[i + 1][1] +
                (restrictions[i + 1][0] - restrictions[i][0])
            )

        answer = 0

        # Find maximum possible peak between adjacent restrictions
        for i in range(1, m):

            x1, h1 = restrictions[i - 1]
            x2, h2 = restrictions[i]

            dist = x2 - x1

            peak = (h1 + h2 + dist) // 2

            answer = max(answer, peak)

        return answer
