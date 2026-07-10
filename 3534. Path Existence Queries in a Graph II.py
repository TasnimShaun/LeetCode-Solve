class Solution:
    def pathExistenceQueries(
        self,
        n: int,
        nums: List[int],
        maxDiff: int,
        queries: List[List[int]]
    ) -> List[int]:

        nodes = []

        for index in range(n):
            nodes.append((nums[index], index))

        nodes.sort()

        position = [0] * n
        values = [0] * n

        for index in range(n):
            values[index] = nodes[index][0]
            position[nodes[index][1]] = index

        LOG = 1
        while (1 << LOG) <= n:
            LOG += 1

        jump = [[0] * n for _ in range(LOG)]

        right = 0

        for left in range(n):

            if right < left:
                right = left

            while (
                right + 1 < n and
                values[right + 1] - values[left] <= maxDiff
            ):
                right += 1

            jump[0][left] = right

        for power in range(1, LOG):
            for index in range(n):
                jump[power][index] = (
                    jump[power - 1][
                        jump[power - 1][index]
                    ]
                )

        answer = []

        for first, second in queries:

            left = position[first]
            right = position[second]

            if left > right:
                left, right = right, left

            if left == right:
                answer.append(0)
                continue

            current = left
            distance = 0

            for power in range(LOG - 1, -1, -1):

                if jump[power][current] < right:

                    current = jump[power][current]

                    distance += (1 << power)

            if jump[0][current] >= right:
                answer.append(distance + 1)
            else:
                answer.append(-1)

        return answer
