class Solution:
    def countCompleteComponents(
        self,
        numberOfNodes: int,
        edges: List[List[int]]
    ) -> int:

        # Build adjacency list
        graph = [[] for _ in range(numberOfNodes)]

        for nodeA, nodeB in edges:
            graph[nodeA].append(nodeB)
            graph[nodeB].append(nodeA)

        visited = [False] * numberOfNodes

        complete_components = 0

        def dfs(current_node):
            nonlocal vertices, degree_sum

            visited[current_node] = True

            vertices += 1
            degree_sum += len(graph[current_node])

            for neighbor in graph[current_node]:
                if not visited[neighbor]:
                    dfs(neighbor)

        for node in range(numberOfNodes):

            if visited[node]:
                continue

            vertices = 0
            degree_sum = 0

            dfs(node)

            if degree_sum == vertices * (vertices - 1):
                complete_components += 1

        return complete_components
